/* today ver.2 --mainの主要部のみ*/
#include <stdio.h>
#include <time.h>
#include "myhtml.h"
int main()
{
    putContentType();
    putHTMLheader("Today2");
    time_t t;
    char* str;
    t = time(NULL);
    str = ctime(&t);
    puts(str);
    putHTMLfooter();
    return 0;
}
