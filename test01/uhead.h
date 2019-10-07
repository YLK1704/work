#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#define NUM 10
#define BUFFER_SIZE 64
struct arg{
	int sum;
	float ave;
};

void urand(int *,int);
void showarray(int *,int);
void showpath(void);
struct arg uoperater(int * ,int );
int writedate(int*a,int n,const char * filename);
int compar(const void *,const void *);
void syssort(int *,int);
void bsort( int*,int);
void runtimes(void (*func)(int *,int),int*,int);
void cp(int* ,int* ,int );
