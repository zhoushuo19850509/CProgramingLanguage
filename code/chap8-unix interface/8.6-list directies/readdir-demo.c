#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "sys/stat.h"
#include "sys/types.h"
// #include "sys/dir.h"
#include "tlpi_hdr.h" 

// #define NAME_MAX 14 // 文件最大的长度 抱歉 syslimits.h中已经定义了
#define DIRSIZ 14 // 目录名称最大长度

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

struct direct{
    ino_t d_ino;   // inode of dir
    char d_name[DIRSIZ]; // dir name
};

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dp);

/**
 * 这个代码为了验证 readdir()方法    
 */
int main(){
    char *dirname = "aaa";
    DIR *dir = opendir(dirname);
    int fd = dir->fd;
    printf("fd of dir: %d , dirname: %s \n", fd, dirname);

    Dirent *dirent = readdir(dir);
    if(dirent != NULL){
        printf("ino of dir: %ld,  filename: %s \n", dirent->ino, dirent->name);
    }else{
        printf("read inode of dir failed ...");
    }
    
}

/**
 * 函数功能：根据fd of dir，调用read() system call，以获取inode of dir
 * @param dp DIR指针，代表fd of dir
 * @return Dirent指针，代表inode of dir
 */
Dirent *readdir(DIR *dp){
    printf("start readdir ... \n");
    printf("fd of dir: %d  \n", dp->fd);

    struct direct dirbuf; 
    static Dirent d;

    int n = read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)); 
    printf("read %d bytes from dir ... \n", n);
    printf("size of dirbuf : %lu \n", sizeof(dirbuf));

    // while(read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)){
    //     printf("enter while ...");
    //     // 如果d_ino为0，说明slot为空
    //     if(dirbuf.d_ino == 0){
    //         continue; 
    //     }
    //     d.ino = dirbuf.d_ino;
    //     strncpy(d.name, dirbuf.d_name, DIRSIZ);
    //     d.name[DIRSIZ] = '\0';  // termination of string
    //     return &d;
    // }
    printf("read nothing , return null ... \n");
    return NULL;
}

/**
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

