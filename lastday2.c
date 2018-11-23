#include <stdio.h>
#include "isleap.h"


int main(){

    int month;
    int lastday;
    int Year;
    int lday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d %d",&Year,&month);
    lastday = lday[month - 1];
    if((month == 2) && (isLeapYear(Year)){
        lastday++;
    }
    printf("%d\n",lastday);
    return 0;
}
    
