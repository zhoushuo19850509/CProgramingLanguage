#include <stdio.h>

#define NAME_MAX 20 // max length of file/dir

// dir 数据结构1 dir entry
typedef struct {
    long ino; // inode of the file/dir
    char name[NAME_MAX +1];  //  name of file/dir
}Dirent;

// dir 数据结构2 
typedef struct {
    int fd;  // 目录对应的file descriptor
    Dirent d; // dir entry for the directory
}DIR;


/**
 * 功能： 
 * 目标： 
*/
int main(){
    printf("hello ...");
}

/**
 * 
*/
void fsize(char *name){

    // 先读取文件的inode信息(stat)

    /**
     * 然后根据inode信息判断当前是文件还是目录
     * 如果是目录，就调用dirwalk(嵌套)遍历这个目录
    */

}

/**
 * dirwalk遍历某个目录
 * @param name 目录名称
 * @param fcn 这是一个函数指针，用于统计filesize
*/
void dirwalk(char *name, void (*fcn)(char *)){

}

/**
 * 根据dirname ，返回DIR
*/
DIR *opendir(char * name){

}

/**
 * 根据DIR ，返回Direntry
*/
Dirent *readdir(DIR *dp){

}

/**
 * 关闭目录
*/
void closedir(DIR *dp){

}



