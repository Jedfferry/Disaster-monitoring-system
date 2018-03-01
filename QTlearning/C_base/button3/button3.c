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

struct Btn_attr{

	int index;
	pthread_t id;
    int x;
    int y;
    int width;
    int height;
    unsigned long color;

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

int  creat_button(struct Btn_attr attr)
{
    int ret,lcd_fd;
    int k,x0,y0,z0;
    unsigned long *fb_mem;


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

   
   for(y0=attr.y;y0< attr.y+attr.height;y0++)
   	 for(x0=attr.x;x0< attr.x+attr.width;x0++)
       	{
	         fb_mem[y0*800+x0]     =   attr.color ;
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


int  button(int index,int x,int y,int width,int height,unsigned long color)
{
    struct Btn_attr Attr={index,0,x,y,width,height,color}; 
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

    button(1,300,100,100,80,1111);
	button(2,300,200,100,80,1111);
	button(3,300,300,100,80,1111);

	while(1);

    return 0;
}



