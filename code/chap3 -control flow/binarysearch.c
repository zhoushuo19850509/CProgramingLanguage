#include <stdio.h>

int binsearch(int x , int v[], int n);

int main(){
    int v[6];
    v[0] = 3;
    v[1] = 9;
    v[2] = 13;
    v[3] = 20;
    v[4] = 99;
    v[5] = 310;
    int index = binsearch(20, v, 6);
    printf("index: %d", index);
}

/* 从数组v中找出元素x */
int binsearch(int x , int v[], int n){
    int mid, low, high;

    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid]){
            high = mid - 1;
        }else if(x > v[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}
