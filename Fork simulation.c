#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("Before Fork\n");
	fork();
	printf("After 1st Fork\n");
	fork();
	printf("After 2nd Fork\n");
	fork();
	printf("After 3rd Fork\n");
	return 0;
}
