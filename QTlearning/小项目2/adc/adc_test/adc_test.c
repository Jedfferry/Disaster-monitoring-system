#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <errno.h>
#include <string.h>

#define ADC_INPUT_PIN	_IOW('S', 0x0c, unsigned long)

int main(void)
{
	fprintf(stderr, "press Ctrl-C to stop\n");
	int fd = open("/dev/adc", O_RDONLY);
	if (fd < 0) {
		perror("open ADC device:");
		return 1;
	}
	ioctl(fd,ADC_INPUT_PIN,0);
	for(;;) {
		unsigned int i;
		read(fd, &i, sizeof(unsigned int));
		//printf("adc = %d\n",i);
		printf("ADC=%d\n",i);
		usleep(500* 1000);
	}
	
	close(fd);
}
