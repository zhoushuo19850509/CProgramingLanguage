#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * 定义hash table的基础数据结构
 * 用于保存symbol table内容，举例如下：
 * #define MAXLEN 100
 * 这里name是MAXLEN，replacement是100
 * 意思就是用MAXLEN代替100这个数字
 * 
 * name: MAXLEN
 * defn: 1000
 * next: next entry in chain 
 *    啥意思呢？可能会有和"MAXLEN"哈希值一样的name，
 *    这些name/replacement节点就以list的形式，
 *    不断添加到当前MAXLEN/1000节点"前面"
 */
struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

// 哈希表的长度
#define HASHSIZE 101

// function declarations
// 获取string的哈希值
unsigned hash(char *s);
// 找到某个string在整个哈希表中的位置
struct nlist *lookup(char *s);
// 把某个name/replacement放到哈希表合适的位置
struct nlist *install(char *s, char *defn);
// 打印哈希表中所有元素
void print_table();

// 哈希表
static struct nlist *hashtab[HASHSIZE];

/**
 * 功能： 实现hash table 
 * 目标： 为了说明struct 在hash table这个数据结构中的作用
 */
int main(){
    // 验证hash()
    // unsigned a = hash("hello\0");
    // printf("a: %d \n", a);

    // 验证install()
    install("hello\0", "1\0");
    install("hi\0", "2\0");
    install("gogogo\0", "3\0");
    print_table();
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
 * 把某个name/replacement放到哈希表合适的位置

 * @return 返回新增的Name/replacement节点的引用
*      如果返回NULL，说明install失败
*/
struct nlist *install(char *s, char *defn){
    struct nlist *np;
    unsigned hashval;
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
    }else{
        // 释放老的name/replacement的defn，为后续的更新defn做准备
        free((void *)np->defn); 
    }
    if((np->defn = strdup(defn)) == NULL){
        return NULL;
    }
    return np;
}

// 打印hash table中所有元素
void print_table(){

    int i;
    struct nlist *np;
    for(i = 0; i < HASHSIZE; i++){
        printf("%4d ", i);
        for(np = hashtab[i]; np != NULL; np = np->next){
            printf("[%s : %s] " , np->name, np->defn);
        }
        printf("\n");
    }
}

