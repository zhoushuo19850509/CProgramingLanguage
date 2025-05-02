#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

/**
 * 本代码的功能： 提供两个函数
     函数1 day_of_year() yyyymmdd -> day of year(某年中的一天)
     函数2 month_day()  day of year(某年中的一天) -> yyyymmdd
 * 目标：为了说明多维数组的使用方法
*/
int main(){
    int date;
    date = day_of_year(2001, 12, 31);
    printf("day of year: %d \n", date);

    int a = 31+28+31+30+31+30+31+31+30+31+30+31;
    printf("非闰年一年总共有多少天%d\n",a);

    int yearday = 365;
    int year = 2001;
    int month;
    int day;
    month_day(year, yearday, &month, &day);
    printf("month: %d , and day of month: %d \n", month, day);

}

// 这个多维数组，记录了非闰年、闰年各个月份的天数
static char daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

// 通过输入的yyyymmdd，计算这天是一年中第一天
int day_of_year(int year, int month, int day){

    int leap; // 是否闰年
    if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        leap = 1; // 闰年
    }else{
        leap = 0; // 非闰年
    }
    
    int i;
    for(i = 1; i < month; i++){
        day = day + daytab[leap][i];
    }
    return day;
}

/**
 * 这个方法是上表面这个day_of_year()的逆向方法
 * 这个方法的功能是把day of year 转化为yyyymmdd
*/
void month_day(int year, int yearday, int *pmonth, int *pday){
    int i;

    int leap; // 是否闰年
    if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        leap = 1; // 闰年
    }else{
        leap = 0; // 非闰年
    }

    for(i = 1; yearday > daytab[leap][i]; i++){
        yearday = yearday - daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;

}

