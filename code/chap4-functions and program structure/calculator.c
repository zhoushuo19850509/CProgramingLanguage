#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'  // 用来标识读取到的是数字

void push(double f);
double pop(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);


// 实现一个计算器
int main(){
    int type; 
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0){
                    push(pop() / op2);
                }else{
                    printf("error! zero divisor!");
                }                
                break;
            case '\n':
                printf("\t %.8g \n", pop());
                break;
            default:
                printf("unknow command! %s \n", s);
                break;
        }
    }
}

// 下面开始定义一个stack的数据结构
#define MAXVAL 100  // stack最多存放的元素数量

int sp = 0;  // stack下一个元素的位置
double val[MAXVAL];  // stack元素都放在这个array中

void push(double f){
    if(sp < MAXVAL){
        val[sp++] = f;
    }else{
        printf("error ! stack is full! ");
    }
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    }else{
        printf("error! stack is empty!");
        return 0.0;
    }
}

/*
 * 功能：不断读取下一个元素： 数字或者操作符
 * @param 如果getop()读取到的是一个数字，
          就以string(char array)的形式返回，放在这个param中
          比如读取到数字234，就返回"234\0",放在s[]中
 * @return 返回元素类型，如果是操作符，
          比如'+'/'-'/'*'/'/'，就返回这些操作符的ASCII码对应的数字
          如果是数字，就返回NUMBER
 */
int getop(char s[]){
    int c;
    int i;

    // 略过空格
    while( (s[0] = (c = getch())) == ' ' || c == '\t'  ){
        ;
    }

    s[1] = '\0';
    // 读取到的字符是非数字，就立即返回，一般来说是'+'/'-'/'*'/'/'这些操作符
    if(!isdigit(c) && c != '.'){
        // printf("return non digit ... %c \n",c);
        return c;
    }
    i = 0;
    // 读取数字（整数部分）
    if(isdigit(c)){
        while( isdigit( s[++i] = (c = getch()) )){
            ;
        }
    }
    // 读取数字（小数部分）
    if(c == '.'){
        while( isdigit( s[++i] = (c = getch()) )){
            ;
        }
    }
    /**
        因为读取到的数字是以string的形式保存在s[]中，
        所以s[]要以'\0'结尾，这已经是惯例了
     */
    s[i] = '\0';
    // 对于多读取的那个字符，要退回去，避免影响下一轮循环
    if(c != EOF){
        ungetch(c);
    }
    // printf("return number: %s \n", s);
    return NUMBER;
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



