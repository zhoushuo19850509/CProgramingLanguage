#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h> // 这个header file专门处理可变个数的参数
#include "tlpi_hdr.h" 

// 指定了打开文件的权限：rw/rw/rw for owner, group ,others
#define PERMS 0666 
#define BUFSIZE 1000

void error(char *fmt, ...);

/**
 * 功能： 模拟unix cp shell脚本，实现文件拷贝
 * 目标： 1.综合利用了open()/creat()这两个unix接口函数，实现文件的打开、创建
 *       2.综合前面的minprintf.c/concatenate-files-v2.c
 *         引入可变参数数量、异常信息打印的功能实现了error()函数打印异常信息
 */
int main(int argc, char *argv[]){

    int f1; // file descriptor of source file
    int f2; // file descriptor of target file

    // 判断参数个数是否符合要求
    if(argc != 3){
        error("Usage: cp from to");
    }

    /**
     * 调用open()函数打开source file
     * 这里要注意open()函数的用法
     * @param 第一个参数要打开的文件的fd
     * @param 第二个参数是打开的权限： READ ONLY
     * @param 第三个参数是perms,open()函数一般是0
     */
    if((f1 = open(argv[1], O_RDONLY, 0)) == -1){
        error("cp : can't read file: %s \n", argv[1]);
    }

    /**
     * 调用creat()函数创建target file
     * @param 第一个参数是要打开的文件的fd
     * @param 第二个参数是以什么权限打开文件，比如0666这种
     */
    if((f2 = creat(argv[2], PERMS)) == -1){
        error("can't create file: %s, mode: %03o ", argv[2], PERMS);
    }

    /**
     * 调用read()/write()函数，把source file内容写入target file:
     * 参考readwrite.c，就是从那个文件拷贝过来的
     * 只不过把原来的标准输入0改成了fd1,把标准输出1改成了fd2
     */
    int n;
    char *buff[BUFSIZE];
    while( (n = read(f1,buff, BUFSIZE)) > 0){
        if((write(f2, buff, n)) != n ){
            error("cp: write error on file: %s ", argv[2]);
        }
    }
    return 0;
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


