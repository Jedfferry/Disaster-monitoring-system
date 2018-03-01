ifneq ($(KERNELRELEASE),)
	obj-m :=adc_drv.o
else
	module-objs :=adc_drv.o
	KERNELDIR :=/home/s5pv210/linux-2.6.35.7-gec
#	KERNELDIR :=/home/s5pv210/linux-2.6.35.7-friend
	PWD :=$(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	cp adc_drv.ko /tftpboot
endif

clean:
	$(RM)  *.ko *.mod.c *.mod.o *.o *.order *.symvers *.cmd
