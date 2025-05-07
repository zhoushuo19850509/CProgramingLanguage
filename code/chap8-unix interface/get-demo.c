#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdarg.h>
#include "tlpi_hdr.h" 

#define BUFSIZE 1000

int get(int fd, long pos, char *buf, int n);
void error(char *fmt, ...);

/**
 * 功能： 这个代码能够实现指定从第n个字节读取某个文件的内容，并打印到console
 *    比如： ./a.out 6 a.txt  
 *    意思就是从6个字节开始读取a.txt内容
 *    如果a.txt的内容是： hello world! Mike welcome to the Disney land!
 *    那么打印到console的内容就是 world! Mike welcome to the Disney land!
 * 目标： 为了说明lseek()函数的作用
 */
int main(int argc, char *argv[]){
    char buff[BUFSIZE];
    int n;
    int fd;
    int pos;
    if(argc != 3){
        error("Usage: get filename pos");
    }

    // 先读取文件
    if((fd = open(argv[1], O_RDONLY, 0)) == -1){
        error("get : can't read file: %s \n", argv[1]);
    }

    // 再读取position
    pos = atoi(argv[2]);

    n = 0;
    while( (n = get(fd, pos, buff, BUFSIZE)) > 0){
        pos += n; 
        write(1, buff, n);
    }
    return 0;
}

int get(int fd, long pos, char *buf, int n){

    if( lseek(fd, pos, 0) >= 0){
        return read(fd, buf, n);
    }else{
        return -1;
    }
}

/**
 * 功能： 打印异常信息到标准异常： stderr，并退出
   备注： 因为error()函数包含可变个数的参数，所以函数可以打印多个异常字段
 * 目标： 综合采用了可变数量参数(参考minprintf.c)、
 *      异常信息打印(参考concatenate-files-v2.c)
 */
void error(char *fmt, ...){
    /**
     * va_list是stdarg.h提供的语法糖，
     * 这厮一个指针，指向各个可变个数的参数
     */
     va_list args;
     va_start(args, fmt);  // va_list指向第一个参数： fmt
     fprintf(stderr, "error: ");
     /**
      * vfprintf()效果和printf()类似，
      * 说白了就是minprintf.c中处理%s/%d/%f的逻辑
      * 上面main()中使用error()打印异常信息的场景，可以明白vfprintf()的功能
      */
     vfprintf(stderr, fmt, args);
     fprintf(stderr, "\n");
     va_end(args);
     exit(1);
}


