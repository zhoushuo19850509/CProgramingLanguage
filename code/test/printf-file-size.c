#include <dirent.h>
#include "tlpi_hdr.h" 
#include "sys/stat.h"

// 某个文件/目录的绝对路径，长度有限制
#define MAX_PATH 1024


void dirwalk(char *dir, void (*fcn)(char *name));
void fsize(char *name);

/**
 * 调用Linux programming interface ， 展示某个dir下的文件
 * 参考《Linux programming interface》 / list_files.c
 */
int main(){


    char *name = "aaa"; // 可以是目录名称，也可以是文件名称

    fsize(name);
}

/**
 * 功能：打印dir/file的名称
 * 如果是dir,可以嵌套打印dir下所有文件的filesize
 * @param name dir/file name
 */
void fsize(char *name){

    struct stat stbuf;

    if(stat(name, &stbuf) == -1){
        fprintf(stderr, "can't access %s \n", name);
        return;
    }

    // 如果判断是dir,就调用 dirwalk()遍历这个目录
    if((stbuf.st_mode & S_IFMT) == S_IFDIR){
        dirwalk(name, fsize);
    }
    // 打印filesize
    printf("%8lld %s \n", stbuf.st_size, name);

}


/**
 * @param dir ： dirname
 * @param fcn ： 函数指针，指向fsize()
 */
void dirwalk(char *dir, void (*fcn)(char *name)){

    struct dirent *dp; // 代表dir inode
    DIR *dfd; // 代表dir fd
    char name[MAX_PATH]; 


    if((dfd = opendir(dir)) == NULL){
        // 利用opendir()打开目录失败
        fprintf(stderr, "dirwalk: can't open dir : %s \n", dir);
        return;
    }

    while((dp = readdir(dfd)) != NULL){
        //skip . .. (current dir /parent dir)
        if(strcmp(dp->d_name, ".") ||
           strcmp(dp->d_name, ".." )){
            continue;
        }
        // dir/file name too long
        else if(strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)){
            fprintf(stderr, "dirwalk: name %s/%s too long \n", dir, dp->d_name);
        }else{
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);

}