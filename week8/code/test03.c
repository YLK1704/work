#include<stdio.h>
#include<stdlib.h>
int a;
static int b=10;
int main(int argc,char* argv[],char *envp[]){
	int a=10;
	char *p=(char*)malloc(sizeof(char));
	printf("a=%d,p=ox %s\n",a,p);
	getchar();
	getchar();
	return 0;
}