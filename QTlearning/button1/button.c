#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <linux/input.h>

int main(int argc,char *argv[])
{
	int lcd_fd,ts_fd;
	int ret;
	unsigned long *fb_mem;
	struct input_event ABS;
	
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
	//清屏黑色
	memset(fb_mem,0x0,800*480*4);


         while(1)
         	{
		//读取坐标  
		ret = read(ts_fd,&ABS,sizeof(ABS));
		if(ret != sizeof(ABS) )
			{
				perror(" Read TS");
				return -1;			
			}

		printf(" ABS type = %d \n",ABS.type);
		printf(" ABS code = %d \n",ABS.code);
		printf(" ABS value = %d \n",ABS.value);

		if(ABS.type == EV_KEY  && ABS.code ==  BTN_TOUCH  && ABS.value == 1 )
			memset(fb_mem,0xFF,800*480*4);
		else if(ABS.type == EV_KEY  && ABS.code ==  BTN_TOUCH  && ABS.value == 0 )
			memset(fb_mem,0x0,800*480*4);
			
         	}
		 
	 munmap(fb_mem, 800*480*4);
	 close(lcd_fd);
	 close(ts_fd);

	 
	return 0;
}


