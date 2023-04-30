#include <stdio.h>

/**
 * 摄氏度(celsius)、华氏度(fahrenheit)的转换 
 * 摄氏度 = 5 * (华氏度 - 32 ) / 9
*/
int main(){
    printf("hello ... \n ");

    int fahr, cels;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while(fahr < upper){
        cels = 5 * (fahr - 32 ) / 9;
        printf("%d \t %d \n" , fahr, cels);
        fahr = fahr + step;
    }

    return 0;

}
