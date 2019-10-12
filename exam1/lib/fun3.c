#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void urand(int *a,int n)
{
	int i,j;
	srand((int)time(0));
	for(i=0;i<10;i++)
	{
		j=1+(int)(100.0*rand()/(RAND_MAX+1.0));
		a[i] = j;
	}
	
}
