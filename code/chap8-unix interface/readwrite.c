#include <stdio.h>
#include "tlpi_hdr.h" 

#define BUFSIZE 1000

int main(){
    char buff[BUFSIZE];
    int n;
    while( (n = read(0,buff, BUFSIZE)) > 0){
        write(1, buff, n);
    }
    return 0;
}
