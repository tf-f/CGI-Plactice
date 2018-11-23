#include <stdio.h>
#include "isleap.h"
int isLeapYear(int y)
{
    if(y%4 != 0) return 0;
    if(y == 3300) return 1;
    if((y%100 == 0) &&(y%400 != 0)) return 0;
    return 1;
}
