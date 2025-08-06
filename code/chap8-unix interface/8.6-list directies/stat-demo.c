#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "tlpi_hdr.h" 

/**
 * 这个demo程序为了验证stat() system call的用法
 * 其实stat()就是根据filename/dir name ,返回inode信息
 */
int main(){
    printf("start-demo start ... \n");
    // char *name = "a.txt";  // 访问一个文件
    char *name = "aaa";    // 访问一个目录
    struct stat stbuf;

    if(stat(name, &stbuf) == -1){
        fprintf(stderr, "can't access %s \n", name);
        return -1;
    }

    // 分别打印inode / size / name
    printf("%llu %8lld %s \n", stbuf.st_ino, stbuf.st_size, name);

    // 备注：如何区分file/dir? stbuf.st_mode可以区分

}
