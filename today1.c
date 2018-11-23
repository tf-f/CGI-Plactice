/* today ver.1 */

#include <stdio.h>
#include <time.h>
#include "myhtml.h"

int main(){
    time_t t;

    putContentType();
    putHTMLheader("today");
    t = time(NULL);
    printf("%ld[sec] from 1970/01/01,00:00:00(UTC)\n",t);
    putHTMLfooter();
    return 0;
}
