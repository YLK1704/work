#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int accmode, val;
	if(argc!=2){
		printf("usage:a.out<desciotor#>");
	}
	if((val=fcntl(atoi(argv[1]),F_GETFL,0))<0)
		printf("fcntl error for fd %d",atoi(argv[1]));
	accmode =val & O_ACCMODE;
	if  (accmode == O_RDONLY)  printf("read only");
	else if(accmode == O_WRONLY)  printf("write only");
	else if(accmode == O_RDWR)  printf("read write");
	else printf("unknown access mode");
	
	if(val & O_APPEND)  printf(",append");
	if(val & O_NONBLOCK)  printf(",nonblocking");
	#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
		if(val & O_SYNC)     printf(",synchronous writes");
	#endif
		printf("\n");
		exit(0);
}	
