#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	pid_t child_pid, parent_pid, my_pid, wid;
	int i=10;
	child_pid=fork();
	if(child_pid<0)
	{
		printf("Fork Failed Exciting\n");
		exit(0);
	}
	if(child_pid==0)
	{
		printf("[CHILD] This is child process\n");
		my_pid=getpid();
		parent_pid=getppid();
		printf("[CHILD] My PID is %d\n", my_pid);
		printf("[CHILD] My Parent's PID is %d\n", parent_pid);
		printf("[CHILD] i= %d\n",--i);
		printf("[CHILD] Child process is going to load another program using execlp system call \n");
		execlp("/bin/pwd","pwd",NULL);
	}
	else
	{
		printf("[PARENT] This is the parent process\n");
		my_pid = getpid();
		parent_pid = getppid();
		printf("[PARENT] My PID is %d\n", my_pid);
		printf("[PARENT] Waiting for child to terminate\n");
		wid = wait(NULL);
		printf("[PARENT] Resuming after termination of %d\n",wid);
		printf("[PARENT] My Parent's PID is %d\n", parent_pid);
		printf("[PARENT] My Child's PID is %d\n", child_pid);
		printf("[PARENT] i= %d\n",++i);
	}
return 0;
}
