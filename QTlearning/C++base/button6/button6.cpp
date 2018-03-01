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




class Widget_Manager;

class Button{

private:


public:

    int index;
    int x;
    int y;
    int width;
    int height;
    unsigned long color;
    const char *pic_name;
    void (*func)(void);
    unsigned long * fb_mem;

    
    Button(Widget_Manager *parent,int X,int Y,int Width,int Height,unsigned long Color,const char *Pic_name,void (*Func)(void));
    ~Button();
    int creat_button(int x,int y,int width,int height,unsigned long color,const char *pic_name);
    void clicked(void);
    

};

typedef struct Btn_Node{

	class Button *btn;
	struct Btn_Node *next;

}BTN_Node;


struct pos{
	int x;
	int y;
};


class Widget_Manager
{
    
private:
    BTN_Node *button_list;
    pthread_t graphic_id;
    int btn_registered;    

public:
    Widget_Manager();
    ~Widget_Manager();
    int lcd_fd;
    int ts_fd;
    unsigned long * fb_mem;
    int button_list_init(void);
    int add_button(class Button* btn);
    int del_button(class Button* btn);
    int treaver_button(void);
    BTN_Node * find_button_by_pos(struct pos ts_pos);
    void button_list_exit(void);
    int graphic_subsys_init(void);
    int graphic_subsys_exit(void);
    friend void* button_pthread(void*arg);
    void get_motion(void *arg);
    void start(void);
};



Widget_Manager :: Widget_Manager()
{
    cout << " Widget_Manager() " << endl;
    graphic_subsys_init();

}

Widget_Manager :: ~Widget_Manager()
{
    cout << " ~Widget_Manager() " << endl;
    graphic_subsys_exit();

}



int Widget_Manager :: button_list_init(void)
{
	
	button_list = new BTN_Node;
	if(button_list == NULL)
	{
		cout << " new new node Failed!" << endl;
		return 0;
	}

	button_list->btn = NULL;
	button_list->next = NULL;

	return 0;
}

int Widget_Manager :: add_button(class Button* btn)
{
	BTN_Node *node,*p;
	btn->index = btn_registered++;
	
	node = new BTN_Node;
	if(node == NULL)
	{
		cout<< " malloc new node Failed!" << endl;
		return 0;
	}

	node->btn = btn;
	node->next = NULL;

	for(p=button_list;p->next != NULL;p = p->next);

	p->next = node;

	return 0;


}


int Widget_Manager :: del_button(class Button* btn)
{
	BTN_Node *p,*q;
	
	for(q=p=button_list ;p != NULL ;q=p,p = p->next)
	{
		if(p->btn->index == btn->index)
		{
				q->next = p->next;
				delete(p);
				break;
		}
			
	}


	return 0;

}

int Widget_Manager :: treaver_button(void)
{

	BTN_Node *p;
	
	for(p=button_list->next ;p != NULL ; p = p->next)
	{
		cout<< " button :  id"<< p->btn->index << endl;
			
	}

	return 0;
}


BTN_Node * Widget_Manager :: find_button_by_pos(struct pos ts_pos)
{

	BTN_Node *p=NULL;
	
	for(p=button_list->next ;p != NULL ; p = p->next)
	{
		if(ts_pos.x >= p->btn->x  &&  ts_pos.x <= (p->btn->x+p->btn->width) &&  ts_pos.y>= p->btn->y  &&  ts_pos.y <= (p->btn->y+p->btn->height))
		{
			cout << "Founed button  :  id" << p->btn->index << endl;
			return p;
		}
			
	}

	return NULL;
}


void Widget_Manager :: button_list_exit(void)
{
	BTN_Node *p,*q;
	
	for(q=p=button_list ;p != NULL ;p = q)
	{
				q = p->next;
				delete(p);
	}
			
}


int Widget_Manager :: graphic_subsys_init(void)
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


int Widget_Manager :: graphic_subsys_exit(void)
{

	munmap(fb_mem, 800*480*4);
	close(lcd_fd);
	close(ts_fd);
	button_list_exit();

	return 0;
}


void  Widget_Manager ::get_motion(void *arg)
{

	int ret;
	struct input_event ts;
	struct pos ts_pos;
    int touch=0;
	BTN_Node *node=NULL;
    

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
        	node->btn->clicked();

    }

    
    
}


void* button_pthread(void*arg)
{  
    Widget_Manager* Manager = (Widget_Manager *)arg;
    Manager->get_motion(NULL);
}


void Widget_Manager :: start(void)
{ 
   // pthread_attr_t attr;
   // pthread_attr_init(&attr);
   // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
   // pthread_create(&tid,&attr,button_pthread,this);
   
    pthread_create(&graphic_id,NULL,button_pthread,this);
    cout<<" start :"<< hex << this <<endl;
    cout<<" pthread :"<< hex << graphic_id <<endl;
}



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


void call_back1(void)
{
    cout<< " call_back1 " << endl;

}

void call_back2(void)
{
    cout<< " call_back2 " << endl;

}

void call_back3(void)
{
    cout<< " call_back3 " << endl;

}


int main(int argc,char *argv[])
{

    Widget_Manager Manager;
    
    
    Button button1(&Manager,300,200,100,80,1111,"btn1.bmp",call_back1);
    Button button2(&Manager,300,300,100,80,1111,"btn2.bmp",call_back2);
    Button button3(&Manager,300,400,100,80,1111,"btn3.bmp",call_back3);

    Manager.start();
    while(1);
  
    return 0;
}



