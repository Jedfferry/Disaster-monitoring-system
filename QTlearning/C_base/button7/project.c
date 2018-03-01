
#include <stdio.h>
#include "graphic.h"


void btn1_func(void *arg)
{
	printf("btn1_func \n");

}


void btn2_func(void *arg)
{
	printf("btn2_func \n");

}

void btn3_func(void *arg)
{
	printf("btn3_func \n");

}


int main(int argc,char *argv[])
{
	graphic_subsys_init();

    button(300,100,100,80,-1,"btn1.bmp",btn1_func);
	button(300,200,100,80,-1,"btn2.bmp",btn2_func);
	button(300,300,100,80,-1,"btn3.bmp",btn3_func);

	graphic_exec();

	while(1);

	graphic_subsys_exit();

    return 0;
}


