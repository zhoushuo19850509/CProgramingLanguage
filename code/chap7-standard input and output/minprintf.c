#include<stdarg.h> // 这个header file专门处理可变个数的参数
#include<stdio.h>

// 模拟printf函数，打印各个参数
void minprintf(char *fmt, ...);

/**
 * 功能： 模拟printf函数，打印各个参数
 * 目标： 利用stdarg.h头文件提供的功能，处理可变个数的参数
 * 备注： 代码中出现的va_list/va_start/va_end/va_arg，
 *       是stdarg.h头文件处理可变个数参数的套路，我们按需使用就行了
 *       核心就是通过va_list这个指针，遍历各个可变个数的参数
 */
int main(){
    char *s = "hello\0";
    minprintf("print string: %s \n" ,s );

    int a = 135;
    minprintf("print int: %d \n" ,a );

    double f = 136.12;
    minprintf("print double: %f \n" ,f );
}

void minprintf(char *fmt, ...){

    /**
     * va_list是stdarg.h提供的语法糖，
     * 这厮一个指针，指向各个可变个数的参数
     */
    va_list ap; 
    char *p; // p是一个指针，用来遍历第一个参数中的各个字符
    char *sval; // 指向string参数,用来处理'%s'类型的参数
    int ival; // 指向int参数,用来处理'%d'类型的参数
    double dval; // 指向double参数,用来处理'%f'类型的参数

    va_start(ap, fmt);  // va_list指向第一个参数： fmt
    for(p = fmt; *p; p++){
        if( *p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){ // 终于碰到%了，这个根据不同场景，予以不同的处理
            case 'd':
                ival = va_arg(ap, int); // 读取一个int类型的参数
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double); // 读取一个double类型的参数
                printf("%f", dval);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++){
                    putchar(*sval);            
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);

}


