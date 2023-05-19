#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	pid_t child_pid, parent_pid, my_pid, wid;
	child_pid=fork();
	if(child_pid<0)
	{
		printf("Fork Failed Exciting\n");
		exit(0);
	}
	if(child_pid==0)
	{	
		//Child Process
		printf("[CHILD] This is child process\n");
		my_pid=getpid();
		parent_pid=getppid();
		printf("[CHILD] My PID is %d\n", my_pid);
		printf("[CHILD] My Parent's PID is %d\n", parent_pid);
		printf("[CHILD] Exiting \n");
		exit(0);
	}
	else
	{	//Parent Process
		printf("[PARENT] This is the parent process\n");
		my_pid = getpid();
		parent_pid = getppid();
		printf("[PARENT] My PID is %d\n", my_pid);
		printf("[PARENT] My Parent's PID is %d\n", parent_pid);
		printf("[PARENT] Sleeping for 10 seconds\n");
		sleep(10);
		printf("[PARENT] Child's PID = %d has ended, but it has an entry in the process table.It is a zombie process\n", child_pid);
	}
	return 0;
}
