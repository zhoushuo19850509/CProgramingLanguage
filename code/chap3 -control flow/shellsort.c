#include <stdio.h>

void shellsort(int v[], int n);

int main(){
    int a[10];
    a[0] = 120;
    a[1] = 12;
    a[2] = 1200;
    a[3] = 1;
    a[4] = 190;
    a[5] = 20;
    a[6] = 1120;
    a[7] = 10;
    a[8] = 1820;
    a[9] = 33;
    shellsort(a, 10);

    int i;
    for(i = 0; i < 10; i++){
        printf("a[%d] : %d \n" ,i, a[i]);
    }
}

/*shell sort排序: 升序排序
  shell sort的核心是理解最里面那个for循环
  意思就是把v[j+gap]这个元素通过不断的比较，放到合适的位置
  这个for循环有点像是冒泡的意思
  但是整体来说shell sort通过gap的形式，提升了冒泡算法的效率
*/
void shellsort(int v[], int n){
    int gap, i, j, temp;

    // loop1 : gap不断除以2
    for(gap = n/2; gap > 0 ;gap = gap/2){
        // loop2: 遍历gap之后的元素
        for(i = gap; i < n ; i++){
            for(j=i-gap; j>=0 && v[j]>v[j+gap]; j = j-gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}


