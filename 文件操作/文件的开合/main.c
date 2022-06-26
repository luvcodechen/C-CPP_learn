#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main()
{
	FILE* fp;
	fp = fopen("file.txt", "w+");
	if (NULL == fp)
	{
		perror("fopen");
	}
	fclose(fp);
	return 0;
}