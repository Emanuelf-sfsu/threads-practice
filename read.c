#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char* argv[]){
void *buf;
char* x =(char*)malloc(100);
size_t count = 100;
off_t offset = 0;

int fd = open("sample.txt", O_RDONLY);

// lseek(fd,0,SEEK_SET);
read(fd,x,100); 
printf("%s\n",x);
printf("Size is %ld", strlen(x));

return 0;
}