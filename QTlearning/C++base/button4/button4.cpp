#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#include <iostream>
using namespace std;



class Button{

private:
    
    int x;
    int y;
    int width;
    int height;
    unsigned long color;
    pthread_t tid;
    const char *pic_name;

public:
    Button(int X,int Y,int Width,int Height,unsigned long Color,const char *Pic_name);
    ~Button();
    int creat_button(int x,int y,int width,int height,unsigned long color,const char *pic_name);
    void clicked(void);
    friend void* button_pthread(void*arg);
    void get_motion(void);
    void start(void);

};

Button :: Button(int X,int Y,int Width,int Height,unsigned long Color,const char *Pic_name)
{
    cout<< " Button()" <<endl;
    
    x = X;
    y = Y;
    width = Width;
    height = Height;
    color = Color;
    pic_name = Pic_name;
    
    creat_button(x,y,width,height,color,pic_name);
    start();
}


Button :: ~Button()
{
   cout<< " ~Button()" <<endl; 
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



int Button :: creat_button(int x,int y,int width,int height,unsigned long color,const char *pic_name)
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
			cout << " open LCD Failed!" << endl;
			return -1;
		}

 
	fb_mem = (unsigned long *)mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
	if(fb_mem == MAP_FAILED)
		{
			cout << " mmap  LCD Failed!\n" << endl;
			return -1;			
		}



   if( pic_name == NULL)
   {
       for(y0=y;y0< y+height;y0++)
       	 for(x0=x;x0< x+width;x0++)
           	{
    	         fb_mem[y0*800+x0]     =   color ;
           	}	       
   }
   else
   {
		bmp_fd = open(pic_name,O_RDONLY);
		if(bmp_fd == -1)
			   {
				   cout << " open BMP Failed!" << endl;
				   return -1;
			   }

		/* 读取位图头部信息 */
		read(bmp_fd,buf,54);
		
		/* 宽度  */
		bmp_width =buf[18];
		bmp_width|=buf[19]<<8;
		
		
		/* 高度  */
		bmp_height =buf[22];
		bmp_height|=buf[23]<<8;
		
		
		/* 像素色深 */
		bmp_type =buf[28];
		bmp_type|=buf[29]<<8;
		pix_byte = bmp_type/8; 
			

		
		/* 获取位图文件的大小 */
		bmp_size=file_size_get(pic_name);

		char bmp_buf[bmp_size-54];
		unsigned long  lcd_buf[bmp_width*bmp_height];
		
		/* 读取所有RGB数据 */
		ret = read(bmp_fd,bmp_buf,bmp_size-54); 
		if(ret == -1)
		{
			cout << " read BMP Failed!" << endl;
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

       for(k=0,y0=y;y0<y+height;y0++,k++)
	   	 for(z=0,x0=x;x0<x+width;x0++,z++)
	       	{
		         fb_mem[(y0)*800+x0]     =   lcd_buf[(bmp_height-1-k)*bmp_width+z] ;
	       	}	       

		close(bmp_fd);

   }
    
	munmap(fb_mem, 800*480*4);
	close(lcd_fd);

	return 0;

}


void Button :: clicked(void)
{
    cout<< " clicked()" <<endl;
    int ret,lcd_fd;
    int k,x0,y0,z0;
    unsigned long *fb_mem;
    

	// 获得LCD操作许可
	lcd_fd =   open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
		{
			cout<< " open LCD Failed!" <<endl;
		}

 
	fb_mem = (unsigned long *)mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
	if(fb_mem == MAP_FAILED)
		{
			cout<< " mmap LCD Failed!" <<endl;		
		}

   
   for(y0=y;y0< y+height;y0++)
   	 for(x0=x;x0< x+width;x0++)
       	{
	         fb_mem[y0*800+x0]     =   ~fb_mem[y0*800+x0] ;
       	}	       

    
	munmap(fb_mem, 800*480*4);
	close(lcd_fd);
   
}




void Button :: get_motion(void)
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
			cout<< " open ts Failed!" <<endl;
		}


    while(1)
    {
    	while(1)
    	{

    		ret = read(ts_fd,&ts,sizeof(ts));
    		if(ret != sizeof(ts) )
    			{
    				cout<< " read ts Failed!" <<endl;			
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

    	
		cout<< " X : " << ts_pos.x << " Y : " << ts_pos.y << endl;

    	if(ts_pos.x >= x  &&  ts_pos.x <= (x+width) &&  ts_pos.y>= y  &&  ts_pos.y <= (y+height))
    	{
            clicked();
    	}

        }

    close(ts_fd);
    
}


void* button_pthread(void*arg)
{  
    Button* button = (Button *)arg;
    button->get_motion();
}


void Button :: start(void)
{ 
   // pthread_attr_t attr;
   // pthread_attr_init(&attr);
   // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
   // pthread_create(&tid,&attr,button_pthread,this);
   
    pthread_create(&tid,NULL,button_pthread,this);
    cout<<" start :"<< hex << this <<endl;
    cout<<" pthread :"<< hex << tid <<endl;
}


int main(int argc,char *argv[])
{
    Button button1(300,200,100,80,1111,"btn1.bmp");
    Button button2(300,300,100,80,1111,"btn2.bmp");
    Button button3(300,400,100,80,1111,"btn3.bmp");

    while(1);
    return 0;
}



