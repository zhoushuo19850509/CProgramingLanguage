#include <stdio.h>

void filecopy(FILE *ifp, FILE *ofp);

/**
 * 功能： 模拟linux cat命令的用法
 *       cat file1 file2 file3 ...
 *       会把所有的文件内容都打印出来
 * 目标： 为了说明stdio.h header file提供的文件操作函数的用法：
 *    fopen(FILE *, char *) 打开文件
 *    getc(FILE *) 逐个字节读取文件
 *    putc(int, FILE *) 逐个字节写入文件
 */
int main(int argc, char *argv[]){
    FILE *fp;

    // 如果没有任何参数，就把标准输入拷贝到标准输出
    if(argc == 1){
        filecopy(stdin, stdout);
    }else{
        while(--argc > 0){
            if( (fp = fopen(*++argv, "r")) == NULL){
                printf("cat: can't open file: %s \n ", *argv);
                return 1;
            }else{
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
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
