#include "uhead.h"

int writedate(int* arr, int len, const char* filename)
{
	int file;
	char buffer[BUFFER_SIZE];
	int n = 0;
	int i;

	if((file = open(filename, O_CREAT | O_RDWR, S_IRWXU | S_IXGRP | S_IROTH | S_IXOTH)) != -1)
	{
		/* 清空文件 */
		ftruncate(file, 0);
		/* 重新设置文件偏移量 */
		lseek(file, 0, SEEK_SET);

		for(i = 0; i < len;)
		{
			if(n <= BUFFER_SIZE - 4)
			{
				n += sprintf(buffer + n, "%d ", arr[i++]);
			}
			else
			{
				write(file, buffer, n);
				n = 0;
			}
		}
		if(n <= BUFFER_SIZE - 1)
		{
			n += sprintf(buffer + n, "\n");
			write(file, buffer, n);
			n = 0;
		}
		else
		{
			write(file, buffer, n);
			n = 0;
			n += sprintf(buffer + n, "\n");
			write(file, buffer, n);
			n = 0;
		}

		close(file);
		return 0;
	}
	else
	{
		printf("file can not be found!\n");
		return -1;
	}
}

