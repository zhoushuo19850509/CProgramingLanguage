#include <stdio.h>
#include <string.h>
#include <ctype.h>

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
char *alloc(int n);
int getlineA(char line[], int lim);
int numcmp(char *s, char *t);
int strcmpv2(char *s, char *t);
void swap(void *v[], int i, int j);
void qsort(void *v[], int left, int right, 
    int (*comp)(void *, void *));
double atof(char s[]);

#define MAXLINE 5000  // 最多读取多少航
char *lineptr[MAXLINE]; // 读取的各行，放在这里

/**
 * 功能： 读取输入的一个文本，每行按照数字的形式进行排序
 * 目标： 为了说明pointer to function的意思。
    啥意思呢？funciton name本身就是指向这个funciton的指针
    我们可以把function name当做一个指针，作为某个函数的参数。
    为啥要把function作为函数的参数呢？这个代码就告诉你为什么。
    因为根据不同情况，要调用不同的函数。
    这有点java中的interface-implement的味道了
    所谓的interface，在这里就是函数的定义，比如numcmp函数和strcmp
    除了函数名称不同，其他的参数、返回值都完全一样：
    int numcmp(char *s, char *t);
    int strcmpv2(char *s, char *t);
    所谓的implement,就是numcmp/strcmpv2这两个函数各自的实现逻辑
 */
int main(int argc, char *argv[]){
    int nlines;
    int numeric = 0; // 是否按照number方式排序

    if(argc > 1 && strcmp(argv[1], "-n") == 0 ){
        numeric = 1;
    }

    if( (nlines = readlines(lineptr, MAXLINE)) > 0){
        qsort((void **) lineptr, 0, nlines - 1,
        (int (*)(void *, void*))(numeric ? numcmp : strcmpv2));
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("input lines too big !");
        return 1;
    }

}


#define MAXLEN 1000 // 每行最长多少字符

int readlines(char *lineptr[], int maxlines){

    int len; // 通过readline()读取到的这行字符串的长度
    int nlines; // 通过readline()读取到了多少行
    char line[MAXLEN];  // 通过readline()读取到的这行，放在这个数组中
    char *p; // 这个指针指向通过readline()读取到的这行字符串

    while( (len = getlineA(line, MAXLEN)) > 0){
        /**
         * 这里一是判断读取到的行数是否过多
         * 二是判断新申请内存是否成功，为啥要新申请内存呢？
         * 因为要存放通过readline()读取到的一行内容
         */
        if( nlines > MAXLINE || 
            ( (p = alloc(len)) == NULL)){
            printf("没法再读更多行了...");
            return -1;
        }else{
            /*
             * 这行代码啥意思知道的吧？通过readline()读取到的这行，是以'\n'结尾的
             * 这里改为以'\0'结尾，意思是当做string了
             */
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    int i;
    for(i = 0; i < nlines; i++){
        printf("%s \n ", lineptr[i]);
    }
}


#define ALLOCSIZE 10000 // 最大能够申请的内存

static char allocbuf[ALLOCSIZE]; // 存放内存的基础数据结构： 数组
static char *allocp = allocbuf;  // 这个指针指向下一个可用的内存地址

char *alloc(int n){
    // 可用内存空间符合申请要求
    if( allocbuf + ALLOCSIZE - allocp > n){
        // 移动一下指针地址，说明本次内存申请生效了
        allocp = allocp + n;
        return allocp - n; // 返回本次申请的可用的内存地址
    }else{
        printf("not enough memory space!");
        return 0;
    }
}

int getlineA(char line[], int lim){
    int i;
    int c;

    for(i = 0 ; i < lim && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    if(c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';  // 每行都以'\n\0'结尾
    return i;
}


void qsort(void *v[], int left, int right, 
    int (*comp)(void *, void *)){

    int last;
    int i;

    if(left >= right){
        return;
    }
    // 把middle element 放到最左边
    swap(v, left, ( left + right )/2 );
    last = left;
    /*
     * 遍历所有元素(除了middle element)
     * 所有小于middle element的元素放到last左边（包括last）
     * 所有大于等于middle element的元素放到last右边
     */
    for( i = left + 1; i <= right; i++){
        if((*comp)(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    // 把middle element放到合适的位置(last的位置)
    swap(v, left, last);
    // 再以middle element为界，利用嵌套的原理，分别给左边、右边排序
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);

}

void swap(void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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

/**
 * 按照数字的方式，比对string大小
 * 实现方式： 就是把string转成浮点数，然后比较浮点数大小
 * @return 返回<0 s < t
           返回0 s == t
           返回>0 s > t
 */
int numcmp(char *s, char *t){
    double v1 = atof(s);
    double v2 = atof(t);

    if(v1 < v2){
        return -1;
    }else if(v1 > v2){
        return 1;
    }else{
        return 0;
    }
}


/*
 * 字符串转float，浮点数
 * “-123.56”
*/
double atof(char s[]){
    // val: 12356 power: 100
    double val, power;
    int i, sign;

    // skip spaces
    for(i = 0; isspace(s[i]); i++){
        ;
    }

    // 处理正负符号
    if(s[i] == '-'){
        sign = -1;
    }else{
        sign = 1;
    }
    if(s[i] == '+' || s[i] == '-'){
        i++;
    }

    // 处理整数段
    for(val = 0.0 ; isdigit(s[i]); i++){
        val = 10 * val + (s[i] - '0');
    }

    // 处理'.'
    if(s[i] == '.'){
        // printf("find floating point ...");
        i++;
    }

    // 处理小数段
    for(power = 1.0 ; isdigit(s[i]); i++){
        val = 10 * val + (s[i] - '0');
        power = power * 10;
    }
    // printf("val: %f \n", val);
    // printf("power: %f \n", power);
    return sign * val / power;
}