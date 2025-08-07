#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h> // 这个header file专门处理可变个数的参数
#include "tlpi_hdr.h" 
#include <sys/dir.h>
#include "dirent.h"
#include <sys/types.h>

#define BUFSIZE 1000

int main(){
    // read a dir
    int fd;
    char *dirname = "aaa";
    fd = open(dirname, O_RDONLY, 0);
    printf("fd of dir  %s is: %d \n", dirname, fd);

    char *buff_dir[BUFSIZE];
    int n;
    n = read(fd,buff_dir, BUFSIZE);
    printf("read %d bytes from dir  %s  \n", n, dirname);
}
