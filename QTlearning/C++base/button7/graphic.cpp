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
#include "graphic.h"
using namespace std;



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




