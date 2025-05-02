#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int c);
int getint(int *pn);

/**
 * 功能： getint()函数从标准输入读取一个个字符，
        如果这些字符组成的是数字，就把数字保存在getint()的参数： *pn中
        *pn是一个指向int类型的指针
   目标： 为了说明指针作为函数参数的场景
*/
int main(){
    int a;
    getint(&a);
    printf("%d \n", a);

}


int getint(int *pn){
    int c, sign;
    // 略过空格
    while(isspace(c = getch())){
        ;
    }
    // 如果读取到的不是数字，就立即返回
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }
    // 处理符号
    if(c == '-'){
        sign = -1;
    }else{
        sign = 1;
    }
    if(c == '-' || c == '+'){
        c = getch();
    }

    // 读取数字
    for(*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }
    *pn = *pn * sign;
    if(c != EOF){
        ungetch(c);
    }
    return c;
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
 
