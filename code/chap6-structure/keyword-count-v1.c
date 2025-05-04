#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS 10   // 我们暂时统计10个关键字
#define MAXWORD 100 //从标准输入读取的word长度，最长是100个字节 

struct key{
    char *word;
    int count;
}keytab[NKEYS] = {
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "const",0,
    "continue",0,
    "default",0,
    "void",0,
    "while",0,
    "for",0,
};

int binsearch(char *word , struct key tab[], int n);
int getword(char *word, int lim);
int getch(void);
void ungetch(int c);

/**
 * 功能： 统计标注输入的C语言关键字(char/const/define这些)
 * 目标： 为了说明array of struct的用法
 */
int main(){
    int n;
    char word[MAXWORD];

    /**
     * 调用getword()不断从标准输入读取word
     * 调用binsearch()判断这个word是否为我们要统计的关键字
     * 如果是关键字，就纳入统计
    */
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            if((n = binsearch(word, keytab, NKEYS)) >=0){
                keytab[n].count++;
            }
        }
    }
    // 打印各个关键字的统计结果
    for(n = 0; n < NKEYS; n++){
        if(keytab[n].count > 0){
            printf("%s : %d \n", keytab[n].word, keytab[n].count);
        }
    }
    printf("\n");
}

/* 从数组v中找出元素x */
int binsearch(char *word , struct key tab[], int n){
    int mid, low, high;

    low = 0;
    high = n - 1;
    int cond;

    while(low <= high){
        mid = (low + high) / 2;
        if( (cond = strcmp(word, tab[mid].word)) < 0){
            high = mid - 1;
        }else if(cond > 0){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

/**
 * 从标准输入中读取一个word
 * @param char *word 从标准输入读取的word(字符串)
 * @param lim 从标准输入读取的最长字符长度
 * @return 返回word对应的字符串的首个char
 */
int getword(char *word, int lim){
    int c;
    char *w = word; // 这个指针指向读取到的word(字符串)

    // 忽略空格
    while( isspace(c = getch())){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    /**
     * 如果读取到的第一个字符不是字母，说明不是word(特指keyword关键字)
     * 处理方式： 立即返回
     */
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    
    // 然后就是不断遍历，一直碰到非字母非数字的字符为止
    for(;--lim > 0; w++){
        if( !isalnum(*w = getch()) ){
            ungetch(*w);
            break;
        }
    }
    // 字符串以'\0'结尾是惯例
    *w = '\0';
    return w[0];
}

/**
 * 下面实现的getch()/unget() 需要有一段缓存，
   用来存放unget()退回来的元素
 */
 #define BUFSIZE 100  // 缓存最多存放的元素，本案例中最多存放一个元素
 char buf[BUFSIZE]; // 缓存就存放在这个buf中
 int bufp = 0;  // 指向缓存下一个空闲的可用位置
 
 int getch(void){
     // 如果缓存中有元素，优先从缓存中取
     if(bufp > 0){
         return buf[--bufp];
     }else{
         // 如果缓存为空，就实时从标准输入获取
         return getchar();
     }
 }
 
 void ungetch(int c){
     if(bufp >= BUFSIZE){
         printf("buffer is full! to many elements in buffer!");
     }else{
         buf[bufp++] = c;
     }
 }
 