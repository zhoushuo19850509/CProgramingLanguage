#include <dirent.h>
#include "tlpi_hdr.h" 


/**
 * 调用Linux programming interface ， 展示某个dir下的文件
 * 参考《Linux programming interface》 / list_files.c
 */
int main(){

    // 目录名称
    char *dirpath = "aaa";
    struct dirent *dp; 

    DIR *dirp;

    // opendir()根据dirpath返回dir fd
    dirp = opendir(dirpath);

    if(dirp == NULL){
        printf("open dir failed ...\n");
        return -1;
    }

    for(;;){
        dp = readdir(dirp);
        if(dp == NULL){
            printf("finish read dir ... \n");
            break;
        }
        printf("dir name : %s \n", dp->d_name);
    }
    // 最后不要忘了关闭dir
    closedir(dirp);
}