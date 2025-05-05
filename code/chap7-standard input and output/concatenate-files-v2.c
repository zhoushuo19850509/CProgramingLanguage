#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

/**
 * 功能： 模拟linux cat命令的用法
 *       cat file1 file2 file3 ...
 *       会把所有的文件内容都打印出来
 *       和concatenate-files.c不同之处在于，
 *       能够在异常场景下，把异常信息通过stderr的形式，打印在console
 * 目标： 为了说明stderr/fprintf在异常处理中的作用
 */
int main(int argc, char *argv[]){
    FILE *fp;
    char *prog = argv[0];  // prog保存了程序的名称

    // 如果没有任何参数，就把标准输入拷贝到标准输出
    if(argc == 1){
        filecopy(stdin, stdout);
    }else{
        while(--argc > 0){
            if( (fp = fopen(*++argv, "r")) == NULL){
                fprintf(stderr,"%s : can't open file: %s \n ", 
                    prog, *argv);
                exit(1); // 程序退出的时候异常
            }else{
                filecopy(fp, stdout);
                fclose(fp);  // 关闭打开的文件，避免资源泄露
            }
        }
    }
    // 写入stdout异常
    if(ferror(stdout)){
        fprintf(stderr,"%s : error writing stdout \n ", prog);
        exit(2); // 程序退出的时候异常
    }
    exit(0);  // 程序退出的时候，一切正常
}

/**
 * 功能: copy file ifp to file ofp
 * 目标：为了说明stdio.h中的getc()/putc()操作文件的功能
 */
void filecopy(FILE *ifp, FILE *ofp){
    int c;
    while( (c = getc(ifp)) != EOF){
        putc(c,ofp);
    }
}
