#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include<signal.h>
#define check_error(return_val,msg){  \
		if(return_val !=0){       \
		    fprintf(stderr,"%s:%s\n",msg,strerror(return_val));\
			exit(-1);\
		}\
	}\
