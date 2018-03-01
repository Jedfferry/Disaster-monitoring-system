#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>


int  creat_button(int x,int y,int width,int height,unsigned long color)
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

   
   for(y0=y;y0< y+height;y0++)
   	 for(x0=x;x0< x+width;x0++)
       	{
	         fb_mem[y0*800+x0]     =   color ;
       	}	       

    
	munmap(fb_mem, 800*480*4);
	close(lcd_fd);

	return 0;

}


int main(int argc,char *argv[])
{
    creat_button(300,200,100,50,1111);

    return 0;
}



