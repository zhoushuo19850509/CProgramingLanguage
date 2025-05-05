#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100 //从标准输入读取的word长度，最长是100个字节 


// binary tree的基本数据结构
struct tnode{
    char *name;
    int count;
    struct tnode *left;
    struct tnode *right;
};

// print the whole tree in order
void treeprint(struct tnode *tree);
// add a word onto the tree
struct tnode *addtree(struct tnode *tree, char *name);
// read a word from the stardard input
int getword(char *word, int lim);
// 申请一段内存，保存树节点
struct tnode *talloc();
int getch(void);
void ungetch(int c);

/**
 * 功能： 统计从标准输入读取的word，进行计数，并按照word升序，打印各个word的计数
 * 目标：为了说明struct self-reference。(struct中的某个元素，是struct本身)
 * 备注： 同时引入了基本数据结构： binary tree
 */
int main(){
    char word[MAXWORD];
    struct tnode *root;
    root = NULL;

    // 不断从标准输入中读取word，如果是符合规范的word，就放到tree上去
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    // 打印整棵树
    treeprint(root);
    return 0;
}


/**
 * print the whole tree in-order
 * 这个in-order的效果，就是按照name进行升序排列
 */
void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%4d %s \n", p->count, p->name);
        treeprint(p->right);
    }
}

/**
 * add a word onto the tree
 * 效果就是name比当前节点name小的放在左边；比当前节点大的放在右边
 * 和当前节点一样的(name相同)，计数+1
 */
struct tnode *addtree(struct tnode *p, char *w){

    int cond;
    if(p == NULL){
        p = talloc(); // 申请一段内存，保存这个tree node
        p->name = strdup(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    }else if( (cond = strcmp(w,p->name)) == 0){
        p->count++;
    }else if(cond < 0){
        p->left = addtree(p->left, w);
    }else{
        p->right = addtree(p->right, w);
    }
    return p;
}

struct tnode *talloc(){
    return (struct tnode *)malloc(sizeof(struct tnode));
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
 