#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define N 10
struct arg{
	int sum;
	float ave;
};

void urand(int *,int);
void show(int *,int);
struct arg uoperater(int * ,int );
int writedate(int*,int);
