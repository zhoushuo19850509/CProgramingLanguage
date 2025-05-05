#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * 定义hash table的基础数据结构
 * 用于保存word出现的次数内容，举例如下：
 * 某个代码文件，比如word-frequency-count.c，”tree“这个word出现了10次
 * 这里name是"tree"，count是10
 * 
 * name: tree
 * count: 10
 * next: next entry in chain 
 *    啥意思呢？可能会有和"tree"这个string的哈希值一样的name，
 *    这些name/count节点就以list的形式，
 *    不断添加到当前MAXLEN/1000节点"前面"
 */
struct nlist{
    struct nlist *next;
    char *name;
    int count;
};

// 哈希表的长度
#define HASHSIZE 101
//从标准输入读取的word长度，最长是100个字节 
#define MAXWORD 100 


// function declarations
// 获取string的哈希值
unsigned hash(char *s);
// 找到某个string在整个哈希表中的位置
struct nlist *lookup(char *s);
// 把某个name/replacement放到哈希表合适的位置
struct nlist *install(char *s);
// 打印哈希表中所有元素
void print_table();
// read a word from the stardard input
int getword(char *word, int lim);
// 申请一段内存，保存树节点
struct tnode *talloc();
int getch(void);
void ungetch(int c);

// 哈希表
static struct nlist *hashtab[HASHSIZE];

/**
 * 功能：统计某个文件中各个word的出现次数，基础数据结构就是hash table
        word/word出现次数以key/value的形式保存在hash table中
        统计完成后，予以打印。
        备注：本代码统计的word count和word-frequency-count.c统计的结果一致
 * 目标：和hash-table.c这个版本一样，
 *      还是为了说明struct 在hash table这个数据结构中的作用
 */
int main(){
    char word[MAXWORD];

    // 不断从标准输入中读取word，如果是符合规范的word，就放到tree上去
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            install(word);
        }
    }
    // 打印所有word
    print_table();
    return 0;

}

// 获取string的哈希值
unsigned hash(char *s){

    unsigned hashvalue;
    for(hashvalue = 0; *s != '\0'; s++){
        hashvalue = *s + 31 * hashvalue;
    }

    return hashvalue % HASHSIZE;
}

// 找到某个string在整个哈希表中的位置
struct nlist *lookup(char *s){
    struct nlist *np;
    // printf("loop up for : %s \n" , s);
    // printf("hash value : %d \n" , hash(s));
    for(np = hashtab[hash(s)]; np != NULL; np = np->next){
        if(strcmp(s, np->name) == 0){
            return np;
        }
    }
    return NULL; // 不好意思，string s在hash table中不存在
}

/*
 * 把某个name放到哈希表合适的位置

 * @return 返回新增的Name/replacement节点的引用
*      如果返回NULL，说明install失败
*/
struct nlist *install(char *s){
    struct nlist *np;
    unsigned hashval;
    int count; 
    // lookup()返回NULL，说明这次要install的Name/replacement是新的
    if( (np = lookup(s)) == NULL){ 
        // 先申请一段内存
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(s)) == NULL){
            return NULL; // 申请内存失败
        }
        hashval = hash(s);
        // 新install的Name/replacement节点，放在list最前面
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
        count = 1;
    }else{
        count = np->count + 1;
    }
    np->count = count;
    return np;
}

// 打印hash table中所有元素
void print_table(){

    int i;
    struct nlist *np;
    for(i = 0; i < HASHSIZE; i++){
        printf("%4d ", i);
        for(np = hashtab[i]; np != NULL; np = np->next){
            printf("[%s : %d] " , np->name, np->count);
        }
        printf("\n");
    }
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
