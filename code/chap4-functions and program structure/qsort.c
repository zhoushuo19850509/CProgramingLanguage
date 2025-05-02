#include <stdio.h>


void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);

/**
 * 代码功能： 快排的方式，进行排序
 * 目标：为了说明嵌套的用法
 */
int main(){
    int v[10] = {100, 9, 51, 22,39, 106, 981, 8,33,298};
    int i;
    printf("before qsort ... \n");
    for(i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    qsort(v, 0, 9);
    printf("after qsort ... \n");
    for(i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void qsort(int v[], int left, int right){

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
        if(v[i] < v[left]){
            swap(v, ++last, i);
        }
    }
    // 把middle element放到合适的位置(last的位置)
    swap(v, left, last);
    // 再以middle element为界，利用嵌套的原理，分别给左边、右边排序
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);

}

void swap(int v[], int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


