
#ifndef __BUTTON__
#define __BUTTON__

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






#endif // __BUTTON__