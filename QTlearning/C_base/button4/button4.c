#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

struct Btn_attr{

	int index;
	pthread_t id;
    int x;
    int y;
    int width;
    int height;
    unsigned long color;
	char *pic_name;

};




void clicked(struct Btn_attr attr)
{
    printf("clicked()\n");
    int ret,lcd_fd;
    int k,x0,y0,z0;
    unsigned long *fb_mem;
    

	// 获得LCD操作许可
	lcd_fd =   open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
		{
			printf(" open LCD Failed!\n");
		}

 
	fb_mem = (unsigned long *)mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
	if(fb_mem == MAP_FAILED)
		{
			printf(" mmap  LCD Failed!\n");		
		}

   
   for(y0=attr.y;y0< attr.y+attr.height;y0++)
   	 for(x0=attr.x;x0< attr.x+attr.width;x0++)
       	{
	         fb_mem[y0*800+x0]     =   ~fb_mem[y0*800+x0] ;
       	}	       

    
	munmap(fb_mem, 800*480*4);
	close(lcd_fd);
   
}




void get_motion(struct Btn_attr attr)
{

    struct pos{
    	int x;
    	int y;
    }ts_pos;

  
	int ret;
	struct input_event ts;
    int touch=0;
    int ts_fd;


	ts_fd =open("/dev/event0",O_RDONLY);
	if(ts_fd == -1)
		{
			printf(" open ts Failed!\n");
		}


    while(1)
    {
    	while(1)
    	{

    		ret = read(ts_fd,&ts,sizeof(ts));
    		if(ret != sizeof(ts) )
    			{
    				printf(" read ts Failed!\n");			
    			}
			
    		if(ts.type == EV_ABS )
    			{
    				if( ts.code == ABS_X)
    					{
    						touch++;
    						ts_pos.x = ts.value;
    					}

    				if( ts.code == ABS_Y)
    					{
    						touch++;
    						ts_pos.y = 479-ts.value;
    					}

    				if(touch == 2)
    					{
    					    touch =0;
    						break;
    					}
                     
    			}
			if(ts.type == EV_SYN)
				{
					bzero(&ts,sizeof(ts));
					bzero(&ts_pos,sizeof(ts_pos));
					touch = 0;
				}

    		}

    	
		printf(" X : %d  Y : %d  \n",ts_pos.x,ts_pos.y);

    	if(ts_pos.x >= attr.x  &&  ts_pos.x <= (attr.x+attr.width) &&  ts_pos.y>= attr.y  &&  ts_pos.y <= (attr.y+attr.height))
    	{
            clicked(attr);
    	}

        }

    close(ts_fd);
    
}

unsigned long file_size_get(const char *pfile_path)
{
	unsigned long filesize = -1;	
	struct stat statbuff;
	
	if(stat(pfile_path, &statbuff) < 0)
	{
		return filesize;
	}
	else
	{
		filesize = statbuff.st_size;
	}
	
	return filesize;
}


int  creat_button(struct Btn_attr attr)
{
    int ret,lcd_fd,bmp_fd;;
    int x0,y0,z0;
    unsigned long *fb_mem;
	int i,j,k,z;
	unsigned char buf[54];
	unsigned int bmp_width;
	unsigned int bmp_height;
	unsigned int bmp_type;
	unsigned int pix_byte;
	unsigned int bmp_size;	
	

	// 获得LCD操作许可
	lcd_fd =   open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
		{
			printf(" open LCD Failed!");
			return -1;
		}

 
	fb_mem = (unsigned long *)mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
	if(fb_mem == MAP_FAILED)
		{
			printf(" mmap  LCD Failed!\n");
			return -1;			
		}

   if(attr.pic_name == NULL )
   {
	   for(y0=attr.y;y0< attr.y+attr.height;y0++)
	   	 for(x0=attr.x;x0< attr.x+attr.width;x0++)
	       	{
		         fb_mem[y0*800+x0]     =   attr.color ;
	       	}	       
   }
   else
   {
		
		bmp_fd = open(attr.pic_name,O_RDONLY);
		if(bmp_fd == -1)
			   {
				   printf(" open BMP Failed!\n");
				   return -1;
			   }

		/* 读取位图头部信息 */
		read(bmp_fd,buf,54);
		
		/* 宽度  */
		bmp_width =buf[18];
		bmp_width|=buf[19]<<8;
		printf("bmp_width=%d\r\n",bmp_width);
		
		/* 高度  */
		bmp_height =buf[22];
		bmp_height|=buf[23]<<8;
		printf("bmp_height=%d\r\n",bmp_height);	
		
		/* 像素色深 */
		bmp_type =buf[28];
		bmp_type|=buf[29]<<8;
		pix_byte = bmp_type/8; 
		printf("bmp_bits =%d  pix_byte = %d \r\n",bmp_type,pix_byte);	

		
		/* 获取位图文件的大小 */
		bmp_size=file_size_get(attr.pic_name);

		char bmp_buf[bmp_size-54];
		unsigned long  lcd_buf[bmp_width*bmp_height];
		
		/* 读取所有RGB数据 */
		ret = read(bmp_fd,bmp_buf,bmp_size-54); 
		if(ret == -1)
		{
			printf(" read  BMP Failed!\n");
			return -1;
		}

       for(j=0,i=0;j< bmp_width*bmp_height;j++,i+=pix_byte)
       	{
				/* 判断当前的位图是否32位颜色 */
				if(bmp_type == 32)
				{
					lcd_buf[j]    =  ( bmp_buf[i] | bmp_buf[i+1] << 8|bmp_buf[i+2] <<16 |bmp_buf[i+3] <<24 );
				}
				else
				{
	    		    lcd_buf[j]    =  ( bmp_buf[i] | bmp_buf[i+1] << 8|bmp_buf[i+2] <<16);
				}
       	}

       for(k=0,y0=attr.y;y0<attr.y+attr.height;y0++,k++)
	   	 for(z=0,x0=attr.x;x0<attr.x+attr.width;x0++,z++)
	       	{
		         fb_mem[(479-y0)*800+x0]     =   lcd_buf[k*bmp_width+z] ;
	       	}	       

		close(bmp_fd);
		
   }

	get_motion(attr);

	munmap(fb_mem, 800*480*4);
	close(lcd_fd);

	return 0;

}

void *new_button(void *arg)
{
    struct Btn_attr attr = *(struct Btn_attr *)arg;
    creat_button(attr);
    free(arg);
}


int  button(int index,int x,int y,int width,int height,unsigned long color,char *pic_file)
{
    struct Btn_attr Attr={index,0,x,y,width,height,color,pic_file}; 
    struct Btn_attr *pAttr = (struct Btn_attr *)malloc(sizeof (struct Btn_attr));
    *pAttr = Attr;
    
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&pAttr->id,&attr,new_button,pAttr);

    return 0;
}

int main(int argc,char *argv[])
{

    button(1,300,100,100,80,-1,"btn1.bmp");
	button(2,300,200,100,80,-1,"btn2.bmp");
	button(3,300,300,100,80,-1,"btn3.bmp");

	while(1);

    return 0;
}



