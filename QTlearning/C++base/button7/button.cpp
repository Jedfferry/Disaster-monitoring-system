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
#include "button.h"
using namespace std;



Button :: Button(Widget_Manager* parent,int X,int Y,int Width,int Height,unsigned long Color,const char *Pic_name,void (*Func)(void))
{
    cout<< " Button()" <<endl;
    
    x = X;
    y = Y;
    width = Width;
    height = Height;
    color = Color;
    pic_name = Pic_name;
    func = Func;
    fb_mem = parent->fb_mem;
    
    creat_button(x,y,width,height,color,pic_name);
    parent->add_button(this);

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
    int ret,bmp_fd;
    int x0,y0,z0;
	int i,j,k,z;
	unsigned char buf[54];
	unsigned int bmp_width;
	unsigned int bmp_height;
	unsigned int bmp_type;
	unsigned int pix_byte;
	unsigned int bmp_size;
    

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
    

	return 0;

}


void Button :: clicked(void)
{
    cout<< " clicked()" <<endl;
    int ret;
    int k,x0,y0,z0;

   
   for(y0=y;y0< y+height;y0++)
   	 for(x0=x;x0< x+width;x0++)
       	{
	         fb_mem[y0*800+x0]     =   ~fb_mem[y0*800+x0] ;
       	}	       

    func();
 
}


