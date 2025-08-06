#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "sys/stat.h"
#include "sys/types.h"
#include "tlpi_hdr.h" 

// #define NAME_MAX 14 // 文件最大的长度 抱歉 syslimits.h中已经定义了

// struct1 代表了目录的inode信息
typedef struct{
    long ino;
    char name[NAME_MAX + 1];
}Dirent;

// struct2 代表了目录的fd
typedef struct{
    int fd;
    Dirent d;
}DIR;

DIR *opendir(char *dirname);

/**
 * 这个代码为了验证opendir()方法
 */
int main(){
    char *dirname = "aaa";
    DIR *dir = opendir(dirname);
    int fd = dir->fd;
    printf("fd of dir: %d , dirname: %s \n", fd, dirname);
}

/**
 * 函数功能：调用open() system call 返回fd of dir
 * @param dirname 目录名称
 * @return 指向结构体DIR的指针，就是代表了目录的fd
 */
DIR *opendir(char *dirname){

    int fd; // fd of dir
    DIR *dp;
    struct stat stbuf;

    /**
     * 这个if判断中做了4件事情：
     * 1.调用open() system call 根据dirname，返回fd
     * 2.调用fstat() system call，根据dir fd获取inode
     * 3.根据inode判断是否为dir
     * 4.调用malloc()为DIR开辟内存空间
     */
    if((fd = open(dirname, O_RDONLY, 0)) == -1
        || fstat(fd, &stbuf) == -1
        || (stbuf.st_mode & S_IFMT) != S_IFDIR
        || (dp = (DIR *)malloc(sizeof(DIR))) == NULL){
        return NULL;
    }
    dp->fd = fd;
    return dp;

}

