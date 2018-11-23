#include <stdio.h>
#include <time.h>
#include "isleap.h"
#include "myhtml.h"

int main()
{
    putContentType();
    putHTMLheader("Today4");
    time_t sec;
    struct tm *tp;
    sec = time(NULL);
    tp = localtime(&sec);
    
    int lday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int lastday;
    lastday = lday[tp -> tm_mon];
    
    printf("Year =%4d\n",tp -> tm_year + 1900); 
    printf("Month =%2d\n",tp -> tm_mon + 1);
    printf("Date =%2d\n",tp -> tm_mday);
    printf("Hour =%02d\n",tp -> tm_hour);
    printf("Min. =%02d\n",tp -> tm_min);
    printf("Sec. =%02d\n",tp -> tm_sec);
    printf("Sflag =%d\n",tp -> tm_isdst);
    
    if( (tp -> tm_mon + 1 == 2) && ( isLeapYear(tp -> tm_year + 1900)) ){
        lastday++;
    }
    
    printf("LastDay is %d\n",lastday);

    putHTMLfooter();
    return 0;
}
    
