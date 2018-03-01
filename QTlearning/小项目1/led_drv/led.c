#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/io.h>
#include <linux/miscdevice.h>
#include <mach/gpio.h>



#define LED1  10
#define LED2  11
#define LED3  12
#define LED4  13

#define LED_ON 0
#define LED_OFF 1


struct miscdevice  led_dev;


static  int  led_open(struct inode * inode, struct file *filp)
{

	return 0;
}


static int  led_ioctl (struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
{

	gpio_set_value(S5PV210_GPJ2(cmd-10),arg);
	
	return 0;
}
	
static int led_release(struct inode *inode, struct file *filp)
{

	return 0;
}




struct file_operations led_fops ={

	.open = led_open,
	.release = led_release,
	.ioctl = led_ioctl,

};



static int  __init  led_init(void)
{
	int ret;
	printk("led_init!\n ");

	led_dev.minor = MISC_DYNAMIC_MINOR ;
	led_dev.name = "led";
	led_dev.fops = &led_fops;

	ret =  misc_register(&led_dev);
	if(ret)
		{
			printk("misc_register  Failed!\n");
			return -EFAULT;
		}

	gpio_request(S5PV210_GPJ2(0),"LED1");
	gpio_request(S5PV210_GPJ2(1),"LED2");
	gpio_request(S5PV210_GPJ2(2),"LED3");
	gpio_request(S5PV210_GPJ2(3),"LED4");

	return 0;

}


static void __exit  led_exit(void)
{
	printk("led_exit!\n ");
	gpio_free(S5PV210_GPJ2(0));
	gpio_free(S5PV210_GPJ2(1));
	gpio_free(S5PV210_GPJ2(2));
	gpio_free(S5PV210_GPJ2(3));
	
	misc_deregister(&led_dev);

}

module_init(led_init);
module_exit(led_exit);



MODULE_LICENSE("GPL");




