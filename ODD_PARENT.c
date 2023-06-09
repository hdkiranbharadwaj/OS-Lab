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
#include<sys/ipc.h>

int main(int argc,char* argv[])
{
	void *ptr;
	int i,k;
	pid_t pid;
		const int SIZE = 4096;
	int shm_fd;
	
	//shm_fd = shmget((key_t)1122,4096,0666|IPC_CREAT);
	//ptr = shmat(shm_fd,NULL,0666);

	if(argc > 1)
		{
			sscanf(argv[1],"%d",&i);
			if(i<1)
		{
				printf("Error Input : %d\n",i);return 0;
		}
		}
	else
	{
		return 1;
	}
	pid = fork();
	if(pid == 0)
	{
	execlp("./odd","odd",argv[1],NULL);
	}
	else if (pid > 0)
	{
		wait(NULL);
		printf("\nPARENT : Child Completed\n");
		
		shm_fd = shmget((key_t)1122,4096,0666|IPC_CREAT);
	ptr = shmat(shm_fd,NULL,0666);
		printf("Parent Printing : \n");
		printf("%s",(char*)ptr);
		shmdt(ptr);
	}
	return 0;	
}
