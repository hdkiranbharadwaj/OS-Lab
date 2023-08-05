//Include   -lrt -o child   while compiling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
void main(int argc, char* argv[]){
	int fd, n;
	int *buffer;
	fd = shm_open("chandan",O_RDWR, 0666);
	buffer = (int*)mmap(NULL, 1024, PROT_WRITE, MAP_SHARED, fd, 0);
	n = atoi(argv[1]);
	buffer[0] = 0;
	buffer[1] = 1;
	for(int i=2; i<n;i++){
		buffer[i] = buffer[i-1] + buffer[i-2];
	}
}
