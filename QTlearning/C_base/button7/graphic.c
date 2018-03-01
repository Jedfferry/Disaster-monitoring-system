

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


#include "graphic.h"



int lcd_fd;
int ts_fd;
pthread_t graphic_id;
unsigned long * fb_mem;
struct Btn_Node* button_list;
int btn_registered=0;


int button_list_init(void)
{
	
	button_list = (struct Btn_Node*)malloc(sizeof(struct Btn_Node));
	if(button_list == NULL)
	{
		printf(" malloc new node Failed!\n");
		return 0;
	}

	bzero(&button_list->btn,sizeof(struct Btn_attr));
	button_list->next = NULL;

	return 0;
}

int add_button(struct Btn_attr *btn)
{
	struct Btn_Node *node,*p;
	btn->index = btn_registered++;
	
	node = (struct Btn_Node*)malloc(sizeof(struct Btn_Node));
	if(node == NULL)
	{
		printf(" malloc new node Failed!\n");
		return 0;
	}

	node->btn = *btn;
	node->next = NULL;

	for(p=button_list;p->next != NULL;p = p->next);

	p->next = node;

	return 0;


}


int del_button(struct Btn_attr *btn)
{
	struct Btn_Node *p,*q;
	
	for(q=p=button_list ;p != NULL ;q=p,p = p->next)
	{
		if(p->btn.index == btn->index)
		{
				q->next = p->next;
				free(p);
				break;
		}
			
	}


	return 0;

}

int treaver_button(void)
{

	struct Btn_Node *p;
	
	for(p=button_list->next ;p != NULL ; p = p->next)
	{
		printf(" button :  id[%d] \n",p->btn.index);
			
	}

	return 0;
}


struct Btn_Node * find_button_by_pos(struct pos ts_pos)
{

	struct Btn_Node *p=NULL;
	
	for(p=button_list->next ;p != NULL ; p = p->next)
	{
		if(ts_pos.x >= p->btn.x  &&  ts_pos.x <= (p->btn.x+p->btn.width) &&  ts_pos.y>= p->btn.y  &&  ts_pos.y <= (p->btn.y+p->btn.height))
		{
			printf("Founed button  :  id[%d] \n",p->btn.index);
			return p;
		}
			
	}

	return NULL;
}


void button_list_exit(void)
{
	struct Btn_Node *p,*q;
	
	for(q=p=button_list ;p != NULL ;p = q)
	{
				q = p->next;
				free(p);
	}
			
}


int graphic_subsys_init(void)
{
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


	ts_fd =open("/dev/event0",O_RDONLY);
	if(ts_fd == -1)
		{
			printf(" open ts Failed!\n");
		}


	button_list_init();

	return 0;
}


int graphic_subsys_exit(void)
{

	munmap(fb_mem, 800*480*4);
	close(lcd_fd);
	close(ts_fd);
	button_list_exit();

	return 0;
}


void clicked(struct Btn_attr attr)
{
    printf("clicked()\n");
    int ret;
    int k,x0,y0,z0;
    
   
   for(y0=attr.y;y0< attr.y+attr.height;y0++)
   	 for(x0=attr.x;x0< attr.x+attr.width;x0++)
       	{
	         fb_mem[y0*800+x0]     =   ~fb_mem[y0*800+x0] ;
       	}	       

    attr.func(NULL);
	  
}




void *get_motion(void *arg)
{

	int ret;
	struct input_event ts;
	struct pos ts_pos;
    int touch=0;
	struct Btn_Node *node=NULL;
    

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

		node = find_button_by_pos(ts_pos);
		if(node != NULL)
        	clicked(node->btn);

    }

    
    
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
    int ret,bmp_fd;
    int x0,y0,z0;
	int i,j,k,z;
	unsigned char buf[54];
	unsigned int bmp_width;
	unsigned int bmp_height;
	unsigned int bmp_type;
	unsigned int pix_byte;
	unsigned int bmp_size;	
	

   if(attr.color != -1)
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

	return 0;

}



int button(int x,int y,int width,int height,unsigned long color,char *pic_file,void (*func)(void *arg))
{
    struct Btn_attr Attr={0,x,y,width,height,color,pic_file,func}; 
    
	add_button(&Attr);
	creat_button(Attr);

    return 0;
}



int graphic_exec()
{

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&graphic_id,&attr,get_motion,NULL);

	return 0;
}

