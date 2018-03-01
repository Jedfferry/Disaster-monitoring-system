
obj-m  +=  led.o

#KER_DIR =  /home/gec/work/android-kernel-samsung-dev

KER_DIR =/home/gec/Download/linux-2.6.35.7-gec

all:
	make -C  $(KER_DIR)  M=`pwd`  modules

clean:
	make -C  $(KER_DIR)  M=`pwd`  clean