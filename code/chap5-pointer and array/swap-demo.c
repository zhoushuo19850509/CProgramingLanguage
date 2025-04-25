#include <stdio.h>

void swap(int *px, int *py);

int main(){
    int a = 1;
    int b = 5;
    swap(&a, &b);
    printf("a: %d, b: %d \n", a, b);

}

void swap(int *px, int *py){
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}
