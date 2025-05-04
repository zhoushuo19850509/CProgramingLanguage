#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100


/**
 * NAME: identifier name
 * PAREN: parenthesis 小括号()
 * BRACKETS: 大括号 []
 */
enum{NAME, PARENS, BRACKETS };

// 函数声明
void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch(void);
void ungetch(int c);

// 变量声明
int tokentype;        // type of last token
char token[MAXTOKEN]; // last token string
char name[MAXTOKEN];  // identifier name
char datatype[MAXTOKEN];  // 数据类型 int,char ...
char out[1000];  // output string

/**
 * 功能：解析函数、变量声明
 * 目标：介绍编译原理的实现原理
*/
int main(){
    while(gettoken() != EOF){
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n'){
            printf("syntax error! \n");
        }
        printf("%s : %s %s \n", name, out, datatype);
    }
}

// 解析指针
void dcl(void){
    int ns;

    // 统计有多少'*'
    for(ns = 0; gettoken() == '*'; ){
        ns++;
    }
    dirdcl();
    while(ns--){
        strcat(out, " pointer to");
    }
}

// 解析declaration
void dirdcl(void){
    int type;

    if(tokentype == '(' ){
        dcl();
        if(tokentype != ')'){
            printf("error!没有找到预期的右括号 ) \n");
        }
    }else if(tokentype == NAME){
        strcpy(name, token);
    }else{
        printf("格式异常！ \n");
    }

    // 开始处理小括号(function)和方括号(数组)
    while( (type = gettoken()) == PARENS || type == BRACKETS){
        if(type == PARENS){
            strcat(out, " function returning");
        }else{
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

/**
 * gettoken()方法的功能是读取一个个token
 * @return tokentype token类型，包括
     tokentype为： PARENS ，对应的token: 就是一对小括号 ()
     tokentype为：( ， 对应的token为空
     tokentype为：BRACKETS 就是中括号 [] 对应的token为[]包括的内容，比如int [10],这里token就位10
     tokentype为： NAME 就是identifier，对应的token为identifier的字符串
 */
int gettoken(void){
    int c;
    char *p = token; 
    // 先处理空格
    while( (c = getch()) == ' ' || c == '\t'){
        ;
    }

    // 处理小括号()
    if(c == '('){
        if((c = getch()) == ')'){
            // 第一种情况： ()
            strcpy(token, "()");
            return tokentype = PARENS;
        }else{
            /**
              * 第二种情况： '('
              * 这里为什么要执行ungetch退回预读取的字符？
              * 因为这个字符是由下一个gettoken()负责读取的
             */
            ungetch(c);
            return tokentype = '(';
        }
    }else if(c == '['){
        // 处理大括号[],通过移动指针p，读取[]中的内容
        for(*p++ = c; (*p++ = getch()) != ']';){
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    }else if(isalpha(c)){
        /**
         * 处理identifier name
         * 备注：处理identifier必须以字母开头，所以这里是isalpha()
         */
        for(*p++ = c; isalnum(c = getch()); ){
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }else{
        return tokentype = c;
    }
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
 


