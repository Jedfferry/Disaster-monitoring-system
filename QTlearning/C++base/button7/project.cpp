
#include "graphic.h"
#include "button.h"

using namespace std;


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


