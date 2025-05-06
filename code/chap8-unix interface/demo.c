#include <stdio.h>
#include <fcntl.h>
#include "tlpi_hdr.h" 

#define BUFSIZE 1000

int main(int arc, char *argv[]){
    char buff[BUFSIZE];
    int n;
    while( (n = read(0,buff, BUFSIZE)) > 0){
        write(1, buff, n);
    }

    int fd;
    fd = open(argv[1], O_RDONLY, 0);

    int pos;
    lseek(fd, pos, 0);

    return 0;
}
