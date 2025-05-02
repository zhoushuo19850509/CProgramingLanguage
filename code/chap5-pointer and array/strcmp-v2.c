#include <stdio.h>

int strcmpv2(char *s, char *t);

/**
 * 功能： 字符串比较
 * 目标： 为了说明指针移动的功能
*/
int main(){
    char *s = "hello\0";
    char *t = "he\0";
    int n = strcmpv2(s, t);
    printf("%d\n", n);
}

/**
 * 比对string大小
 * 实现方式： 数组操作
 * @return 返回<0 s < t
           返回0 s == t
           返回>0 s > t
 */
int strcmpv2(char *s, char *t){

    for(; *s == *t; s++, t++){
        // 到达任何一个数组末尾
        if((*s == '\0') && (*t == '\0')){
            return 0;
        }
    }
    return *s - *t;
}