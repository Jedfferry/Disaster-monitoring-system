# Makefile2.6
#kbuild syntax. dependency relationshsip of files and target modules are listed here.
obj-m += input_key.o
PWD  := $(shell pwd)

# where the kernel sources are located
KERN_DIR =  /home/gec/Download/linux-2.6.35.7-gec
#KERN_DIR=/lib/modules/$(KERN_VER)/build


modules:
	$(MAKE) -C $(KERN_DIR) M=$(PWD) modules
	
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions

