#include<stdio.h>
void main()
{
	char fn[10];
	printf("Enter source filename\n");
	scanf("%s",fn);
	if(remove(fn)==0)
		printf("File removed\n");
	else 
	    printf("File cannot be removed\n");
}
