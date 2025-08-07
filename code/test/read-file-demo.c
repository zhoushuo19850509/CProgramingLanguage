#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h> // 这个header file专门处理可变个数的参数
#include "tlpi_hdr.h" 

#define BUFSIZE 1000

int main(){
    // read a file
    int fd;
    char *filename = "a.txt";
    fd = open(filename, O_RDONLY, 0);
    printf("fd of file  %s is: %d \n", filename, fd);

    int n;
    char *buff[BUFSIZE];
    n = read(fd,buff, BUFSIZE);
    printf("read %d bytes from file  %s  \n", n, filename);



}
