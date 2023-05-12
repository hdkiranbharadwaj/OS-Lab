#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>

void main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;
	if(argc<2)
	{
	  printf("\n You are not passing the directory\n");
	  exit(1);
	}
	if((dp=opendir(argv[1]))==NULL)
	{
	  printf("\nCannot open it doesn't exist %s file \n", argv[1]);
	  exit(1);
	}
	while((dirp=readdir(dp))!=NULL)
	  printf("%s\n", dirp->d_name);
	closedir(dp);
}	  
	  
