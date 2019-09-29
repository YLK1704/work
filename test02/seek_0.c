#include "shead.h"

int main(void)
{
	int fd;
	if((fd==creat("file.hole",O_RDWR))<0)
		printf("creat error");
	if(write(fd,buf1,10)!=10)
		printf("buf1 write error");
	if(lseek(fd,40,SEEK_SET)== -1)
		printf("lseek error");
	if(write(fd,buf2,10)!=10)
		printf("buf2 write error");
	return 0;
}
