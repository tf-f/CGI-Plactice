#include <stdio.h>
#include <time.h>
#include "myhtml.h"

int main()
{
    time_t sec;
    struct tm *tp;
    putContentType();
    putHTMLheader("Today3");
    sec = time(NULL);
    tp = localtime(&sec);
    printf("Year =%4d\n",tp -> tm_year + 1900);
    printf("Month =%2d\n",tp -> tm_mon + 1);
    printf("Date =%2d\n",tp -> tm_mday);
    printf("Hour =%02d\n",tp -> tm_hour);
    printf("Min. =%02d\n",tp -> tm_min);
    printf("Sec. =%02d\n",tp -> tm_sec);
    printf("Wday =%d\n",tp -> tm_wday);
    printf("Yday =%d\n",tp -> tm_yday);
    printf("Sflag =%d\n",tp -> tm_isdst);
    putHTMLfooter();
    return 0;
}
