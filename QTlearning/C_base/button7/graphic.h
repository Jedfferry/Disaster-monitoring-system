

#ifndef __GRAPHIC__
#define __GRAPHIC__


struct Btn_attr{

	int index;
    int x;
    int y;
    int width;
    int height;
    unsigned long color;
	char *pic_name;
	void (*func)(void *arg);

};


struct Btn_Node{

	struct Btn_attr btn;
	struct Btn_Node* next;

};


struct pos{
	int x;
	int y;
};



int graphic_subsys_init(void);
int graphic_subsys_exit(void);
int button(int x,int y,int width,int height,unsigned long color,char *pic_file,void (*func)(void *arg));
int graphic_exec();




#endif



