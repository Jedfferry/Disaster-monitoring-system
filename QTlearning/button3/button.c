#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <linux/input.h>
#include <stdlib.h>

struct ts_code{

	int x;
	int y;

};

struct Widget_Attr{

	int x;
	int y;
	int width;
	int height;
	unsigned long color;
	void (*FuncA)();
	void (*FuncB)();

};


int lcd_fd,ts_fd;
int ret;
unsigned long *fb_mem;
struct input_event ABS;





void Fun_Press()
{
	memset(fb_mem,0xFF,800*480*4);
}

void Fun_Release()
{
	memset(fb_mem,0x0,800*480*4);
}


struct ts_code  get_ts(void)
{
	struct ts_code ts;
	int count = 0;

        while(1)
         	{
		//读取坐标  
		ret = read(ts_fd,&ABS,sizeof(ABS));
		if(ret != sizeof(ABS) )
			{
				perror(" Read TS");
			}


		if(ABS.type == EV_ABS   ) //触摸事件
			{
				if(ABS.code == ABS_X  &&  ABS.value != 0  ) 
					{
                                                         ts.x =   ABS.value;
						count ++;								
					}	
				if(ABS.code == ABS_Y  &&  ABS.value != 0 ) 
					{
                                                        ts.y =   479-ABS.value;
					        count ++;
					}
				if(count == 2 )
					break;
			}
			
         	}

	return ts;

}



int  create_widget(int x,int y,int width,int height,unsigned long color,void (*FuncA)(),void (*FuncB)())
{
	int x0,y0;
	struct ts_code ts;

	//打开LCD
	lcd_fd = open("/dev/fb0",O_RDWR);
	if(lcd_fd == -1)
		{
			perror(" Open LCD");
			return -1;
		}
	//打开TS
	ts_fd = open("/dev/event0",O_RDWR);
	if(ts_fd == -1)
		{
			perror(" Open TS");
			return -1;
		}	

	//映射显存
	fb_mem = mmap(NULL, 800*480*4,  PROT_WRITE|PROT_READ, MAP_SHARED, lcd_fd, 0);
	if(fb_mem == MAP_FAILED)
		{
			perror(" Mmap LCD");
			return -1;
		}


	for(y0=y;y0<y+height;y0++)
		for(x0=x;x0<x+width;x0++)
			{
				fb_mem[y0*800+x0] = color;
			}

          while(1)
          	{
		           ts = get_ts();
		           printf("  ts  y: %d    x:%d !\n",ts.y,ts.x);
	                     printf("  ts  Y : %d - %d     X:%d  -%d!\n",y,y+height,x,x+width);
		           if(ts.x >= x  && ts.x <= (x+width)   &&  ts.y > y && ts.y <= (y+height))
		           	{	
		                                    printf("  click !\n");
				 }
          	}
		 
	 munmap(fb_mem, 800*480*4);
	 close(lcd_fd);
	 close(ts_fd);

	return 0;
}

void *widget_thread(void *arg)
{
	struct Widget_Attr *attr=(struct Widget_Attr *)arg;
	create_widget(attr->x,attr->y,attr->width,attr->height,attr->color, attr->FuncA,attr->FuncB);
}

int   create_button(int x,int y,int width,int height,unsigned long color,void (*FuncA)(),void (*FuncB)())
{
      pthread_t  id; 
      struct Widget_Attr  Attr = {x,y,width,height,color,FuncA,FuncB}; 
      struct Widget_Attr *attr=(struct Widget_Attr *)malloc(sizeof(struct Widget_Attr ));
      *attr = Attr;	  	
      
      pthread_create(&id,NULL,widget_thread,attr);

	return 0;
}



int main(int argc,char *argv[])
{

	
	create_button(100,200,150,150,0x88888888, Fun_Press,Fun_Release);
	create_button(400,300,150,150,0x88888888, Fun_Press,Fun_Release);

	while(1);
	
	return 0;
}


