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
         //int k=2,n1,n2,n3;
         void*ptr;
         int shm_fd = shm_open("OS", O_CREAT | O_RDWR, 0667);
         ftruncate(shm_fd,4096);
         ptr = mmap(0,4096,PROT_WRITE, MAP_SHARED, shm_fd, 0);
         printf("CHILD:\n");
         int i=atoi(argv[1]);
		 int j = atoi(argv[2]);
         if(i ==1 || i == 2)
		 {
         sprintf(ptr,"2 ");
		 printf("2 ");
         ptr+=strlen(ptr);
		 i++;
		 if(i == 2)
		 	i++;
		 }
		 
		 for(int m = i;m<=j;m++)
		 {
		 	int flag = 0;
		 	for(int n = 2;n<m;n++)
		 	{
		 		if(m%n == 0)
		 			flag = 1;
			}
		 	if(flag == 0)
		 	{
		 		printf("%d ",m);
         			sprintf(ptr,"%d ",m);
        			ptr+=strlen(ptr);
		 	}
		 	
		 }
}
