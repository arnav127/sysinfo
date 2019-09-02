#include<stdio.h>

int main()
{
	int i=0, a, n;
	char c, num[10];
	system("sudo dmidecode | grep 'Installed Size' > cac");
	system("cat /proc/meminfo | grep 'MemTotal' > mem");
	FILE *fptr;
	printf("\nSystem Cache Sizes:\n");
	fptr = fopen("cac", "r");
	do
	{
		c = fgetc(fptr);
		if(c==':')
		{
			i++;
			printf("L%d:", i);
			while(c!='\n')
			{
				c=fgetc(fptr);
				printf("%c", c);
			}
		}
	}while(c!= EOF);
	fptr = fopen("mem", "r");
	i=0;
	do
	{
		c = fgetc(fptr);
		if(c>='0'&&c<='9')
			num[i++]=c;
	}while(c!=EOF);
	n=atoi(num);
	n/=1024;
	printf("Total Memory Size: %dmB\n", n);
	fclose(fptr);
	return 0;
}
