#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <asm/irq.h>
#include <asm/uaccess.h>
#include <mach/regs-gpio.h>
#include <mach/hardware.h>
#include <mach/irqs.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/input.h>



struct input_dev* button_devp;

struct button_irq_desc{
	 int irq;
	 int pin;
	 int number;
	 char *name;
};

static struct button_irq_desc button_irqs[] = {
 {IRQ_EINT(16) , S5PV210_GPH2(0), 0, "KEY0"},
 {IRQ_EINT(17), S5PV210_GPH2(1), 1, "KEY1"},
 {IRQ_EINT(18), S5PV210_GPH2(2), 2, "KEY2"},
 {IRQ_EINT(19), S5PV210_GPH2(3), 3, "KEY3"},
 {IRQ_EINT(24), S5PV210_GPH3(0), 4, "KEY4"},
 {IRQ_EINT(25), S5PV210_GPH3(1), 5, "KEY5"},
 {IRQ_EINT(26), S5PV210_GPH3(2), 6, "KEY6"},
 {IRQ_EINT(27), S5PV210_GPH3(3), 7, "KEY7"},
};

static irqreturn_t  button_interrupt(int irq, void* dev_id)
{
 struct button_irq_desc *button_irqs = (struct button_irq_desc*)dev_id;
 int down; 
 
 down = gpio_get_value(button_irqs->pin);
 mdelay(10);

	 if(down == gpio_get_value(button_irqs->pin))
	 {
		 switch(button_irqs->irq)
		 {
		  case IRQ_EINT(16):
		   input_report_key(button_devp, KEY_1, !down);
		   input_sync(button_devp);
		   break;
		  case IRQ_EINT(17):
		   input_report_key(button_devp, KEY_2, !down);
		   input_sync(button_devp);  
		   break;
		  case IRQ_EINT(18):
		   input_report_key(button_devp, KEY_3, !down);
		   input_sync(button_devp);      
		   break;
		  case IRQ_EINT(19):
		   input_report_key(button_devp, KEY_4, !down);
		   input_sync(button_devp);      
		   break;
		  case IRQ_EINT(24):
		   input_report_key(button_devp, KEY_5, !down);
		   input_sync(button_devp);      
		   break;
		  case IRQ_EINT(25):
		   input_report_key(button_devp, KEY_6, !down);
		   input_sync(button_devp);       
		   break;
		  case IRQ_EINT(26):
		   input_report_key(button_devp, KEY_7, !down);
		   input_sync(button_devp);	   
		   break;
		  case IRQ_EINT(27):
		   input_report_key(button_devp, KEY_8,! down);
		   input_sync(button_devp);		
		   break;
		  default:
		   break;
		 }
		 
	}
	 
	 return IRQ_RETVAL(IRQ_HANDLED);
}

static int __init button_init(void)
{
        int i,  err;
 
         button_devp = input_allocate_device();

	 for(i = 0; i < sizeof(button_irqs)/sizeof(button_irqs[0]); i++)
	 {
		  if(button_irqs[i].irq < 0)
			  {
			  	 continue;
			  }

	 	 err = request_irq(button_irqs[i].irq, button_interrupt, IRQ_TYPE_EDGE_BOTH, button_irqs[i].name, (void *)&button_irqs[i]);
		  if(err)
		  {
			   printk("request_irq fail!\n");
			   break;
		  }
	 }
 
	 if(err)
	 {
	  	i--;
		  for(; i >= 0; i--)
			  {
				   if(button_irqs[i].irq < 0)
				   {
				   	 continue;
				   }
				   disable_irq(button_irqs[i].irq);
				   free_irq(button_irqs[i].irq, (void*)&button_irqs[i]);
			  }
	  	return -EBUSY;
	 }
        
	  set_bit(EV_KEY, button_devp->evbit);

	  set_bit(KEY_1, button_devp->keybit);
	  set_bit(KEY_2, button_devp->keybit);
	  set_bit(KEY_3, button_devp->keybit);
	  set_bit(KEY_4, button_devp->keybit);
	  set_bit(KEY_5, button_devp->keybit);
	  set_bit(KEY_6, button_devp->keybit);
	  set_bit(KEY_7, button_devp->keybit);
	  set_bit(KEY_8, button_devp->keybit);

  	 input_register_device(button_devp);
  
 	 return 0;
}

static void __exit button_exit(void)
{
 int i = 7;
    input_unregister_device(button_devp);
    for(i = 7; i >= 0; i--)
 {
  if(button_irqs[i].irq < 0)
  {
   continue;
  }
  disable_irq(button_irqs[i].irq);
  free_irq(button_irqs[i].irq, (void*)&button_irqs[i]);
 }
}

module_init(button_init);
module_exit(button_exit);


MODULE_AUTHOR("gec");
MODULE_LICENSE("GPL");

