#include <stdio.h>
#include "isleap.h"

int main(){
    int month;
    int lastday,Year;
    scanf("%d%d",&Year,&month);
    
    switch(month){
    case 2:
        if(isLeapYear(Year)) lastday = 29;
	else lastday = 28;
	break;
    case 4:
    case 6:
    case 9:
    case 11:
        lastday = 30;
	break;
    default:
        lastday = 31;
	break;
    }
    printf("%d\n",lastday);
    return 0;
}
