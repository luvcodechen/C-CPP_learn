#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

int main()
{
	FILE* fp;
	char c = 0;
	fp = fopen("file.txt", "r+");//w+:����һ���ļ��ɶ�д�����Ѵ���������
	char buf[20] = { 0 };
	if (fp)
	{
		//for(c='A'; c <= 'Z';c++)
		//fputc(c, fp);
		//fputc('A', fp);
		//fwrite(buf,1,10,fp);
		//(buf,0,sizeof(buf));
		//fseek(fp,0,SEEK_SET);
		//fread(buf, sizeof(char), 15 , fp);
		fgets(buf,11,fp);
		puts(buf);
	/*	c=getchar();
		putchar(c);*/
		fclose(fp);
	}

	return 0;
}