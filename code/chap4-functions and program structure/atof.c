#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

/**
 * 这个代码的功能： atof() 字符串转float number
 * 为了说明function可以返回非int类型的元素
 */
int main(){
    char *s = "-123.45";
    double f;
    f = atof(s);
    printf("%f \n", f);

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
