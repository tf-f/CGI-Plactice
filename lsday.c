#include <stdio.h>
#include "lsday.h"

int isLeapYear(int y)
{
    if(y%4 != 0) return 0;
    if(y == 3300) return 1;
    if((y%100 == 0) &&(y%400 != 0)) return 0;
    return 1;
}

int LastDay(int year,int month){
    int lastday;
    int lday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    lastday = lday[month - 1];
    if((month == 2) && isLeapYear(year)){
        lastday++;
    }
    
    return lastday; 
}
    
