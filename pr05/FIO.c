#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define Buffersize 30
int main()
{
    int fd, n;
    char buffer[Buffersize], fname[Buffersize];

    printf("Enter Filename : ");
    scanf("%s", fname);
    fd = open(fname, O_RDWR);
    printf("File Description is %d\n", fd);

    if (fd == -1)
    {
        printf("Failed to open File!\n");
        exit(0);
    }

    printf("Reading first 10 charecters from file...\n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nSkipping 5 characters from current pos : \n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nGoing to 5th last character in the file...\n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);

    printf("\nGoing to 3rd character in the file...\n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 5);
    write(1, buffer, n);

    printf("\n\n");
    return 0;
}
