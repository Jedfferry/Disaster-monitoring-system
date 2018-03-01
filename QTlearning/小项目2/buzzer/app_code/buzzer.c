#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <limits.h>

#define  BUZZER_IOCTL_SET_FREQ 1
#define  BUZZER_IOCTL_STOP 0


void Usage(char *args)
{
	printf("Usage: %s <on/off> <freq>\n",args);
	return ;
}

int main(int argc , char **argv)
{
	int buzzer_fd;
	unsigned long freq;
	char *endstr, *str;
	printf("Usage: %s <on/off> <freq>\n","./buzzer");
	
	if(argc==3){	
		buzzer_fd = open("/dev/pwm",O_RDWR);
		if(buzzer_fd<0){
			perror("open device:");
			exit(1);
		}
		
		str = argv[2];
		errno = 0;
		freq = strtol(str , &endstr, 0);
	
		if((errno == ERANGE &&(freq == LONG_MAX ||freq ==LONG_MIN))||(errno !=0 && freq ==0)){
			perror("freq :");
			exit(EXIT_FAILURE);
		}
		if(endstr ==str){
			fprintf(stderr , "Please input a digits for freq\n");
			exit(EXIT_FAILURE);
		}
		
		if(!strncmp(argv[1], "on" ,2)){
			ioctl(buzzer_fd, BUZZER_IOCTL_SET_FREQ , freq );
		}	
		else if(!strncmp(argv[1], "off", 3)){
			ioctl(buzzer_fd , BUZZER_IOCTL_STOP , freq);
		}
		else{
			close(buzzer_fd);
			exit(EXIT_FAILURE);
		}	
	}
	else if(argc ==2){
		buzzer_fd = open("/dev/pwm",O_RDWR);
		if(buzzer_fd<0){
			perror("open device:");
			exit(1);
		}

		if(!strncmp(argv[1], "off", 3)){
			ioctl(buzzer_fd , BUZZER_IOCTL_STOP , freq);
		}
		else{
			close(buzzer_fd);
			exit(EXIT_FAILURE);
		}		
	}
	else {
		Usage(argv[0]);
		exit(EXIT_FAILURE);
	}
	
	
	close(buzzer_fd);
	return 0;
}
