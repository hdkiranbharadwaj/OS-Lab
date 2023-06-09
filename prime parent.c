//7b parent
 //PARENT PROCESS

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc,char* argv[])
{
	void *ptr;
	int i;
	pid_t pid;
		const int SIZE = 4096;
	int shm_fd;

	if(argc > 2)
		{
			sscanf(argv[1],"%d",&i);
			if(i<1)
		{
				printf("Error Input : %d\n",i);return 0;
		}
		}
	else
	{
		printf("Error not passing n in Command line \n");exit(0);
	}
	pid = fork();
	if(pid == 0)
	{
	execlp("./prime","prime",argv[1],argv[2],NULL);
	}
	else if (pid > 0)
	{
		wait(NULL);
		printf("\nPARENT : Child Completed\n");
		
		shm_fd = shm_open("OS",O_RDONLY,0667);
		ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
		printf("Parent Printing : \n");
		printf("%s",(char*)ptr);
		shm_unlink("OS");
	}
	return 0;	
}
