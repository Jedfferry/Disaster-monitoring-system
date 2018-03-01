
#ifndef __GRAPHIC__
#define __GRAPHIC__

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


class Button;

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




#endif // __GRAPHIC__