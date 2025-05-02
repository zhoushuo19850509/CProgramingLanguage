#include <stdio.h>

int strcmpv1(char *s, char *t);

/**
 * 功能： 字符串比较（数组实现）
 * 目标： 为了说明数组方式实现字符串比较
*/
int main(){
    char *s = "hello\0";
    char *t = "he\0";
    int n = strcmpv1(s, t);
    printf("%d\n", n);
}

/**
 * 比对string大小
 * 实现方式： 数组操作
 * @return 返回<0 s < t
           返回0 s == t
           返回>0 s > t
 */
int strcmpv1(char *s, char *t){

    int i;
    for(i = 0; s[i] == t[i]; i++){
        // 到达任何一个数组末尾
        if((s[i] == '\0') && (t[i] == '\0')){
            return 0;
        }
    }
    return s[i] - t[i];

}