#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
         int k=0;
int n = 1;
         void*ptr;
         int shm_fd = shmget((key_t)1122,4096,0666);
        // ftruncate(shm_fd,4096);
         ptr =shmat(shm_fd,NULL, 0666);
         printf("CHILD:\n");
         int i=atoi(argv[1]);
         
        
         while (k<i)
         {
                
                sprintf(ptr,"%d ", n);
                printf("%d ", n);
                ptr += strlen(ptr);
                k++;
n = n+2;
	}
printf("\n");
//shmctl(shm_fd,IPC_RMID,NULL);
return 0;
}                                       
