ifneq ($(KERNELRELEASE),)
	obj-m :=buzzer_drv.o
else
	module-objs :=buzzer_drv.o
	KERNELDIR :=/home/gec/linux_kernel/linux-2.6.35.7/
	PWD :=$(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif

clean:
	$(RM)  *.ko *.mod.c *.mod.o *.o *.order *.symvers *.cmd