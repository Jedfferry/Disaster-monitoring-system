#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>


#include <iostream>
using namespace std;



class Button{

private:
    
    int x;
    int y;
    int width;
    int height;
    unsigned long color;

public:
    Button(int X,int Y,int Width,int Height,unsigned long Color);
    ~Button();
    int creat_button(int x,int y,int width,int height,unsigned long color);
    void clicked(void);
    void get_motion(void);

};

Button :: Button(int X,int Y,int Width,int Height,unsigned long Color)
{
    cout<< " Button()" <<endl;
    
    x = X;
    y = Y;
    width = Width;
    height = Height;
    color = Color;
    
    creat_button(x,y,width,height,color);
    get_motion();
}


Button :: ~Button()
{
   cout<< " ~Button()" <<endl; 
}


int Button :: creat_button(int x,int y,int width,int height,unsigned long color)
{
    int ret,lcd_fd;
    int k,x0,y0,z0;
    unsigned long *fb_mem;
    

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

   
   for(y0=y;y0< y+height;y0++)
   	 for(x0=x;x0< x+width;x0++)
       	{
	         fb_mem[y0*800+x0]     =   color ;
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

    		}

    	
		cout<< " X : " << ts_pos.x << " Y : " << ts_pos.y << endl;

    	if(ts_pos.x >= x  &&  ts_pos.x <= (x+width) &&  ts_pos.y>= y  &&  ts_pos.y <= (y+height))
    	{
            clicked();
    	}

        }

    close(ts_fd);
    
}



int main(int argc,char *argv[])
{
    Button button(300,200,100,50,1111);
    return 0;
}



