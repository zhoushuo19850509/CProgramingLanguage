#include <stdio.h>

struct point{
    int x; 
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};

struct point makePoint(int x, int y);

int main(){

    printf("hello structure ...");


}

// 根据x/y生成point结构体
struct point makePoint(int x, int y){
    struct point tmp;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}

// 两个point相加
struct point addPoint(struct point a, struct point b){
    struct point tmp;
    tmp.x = a.x + b.x;
    tmp.y = a.y + b.y;
    return tmp;
}

int ptinrect(struct point p, struct rect r){
    return p.x >= r.pt1.x && p.x <= r.pt2.x && p.y >= r.pt1.y && p.y <=r.pt2.y;
}

