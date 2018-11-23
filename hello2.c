/* Hello World -CGI Version */
#include <stdio.h>
#include "myhtml.h"

int main()
{
    putContentType();
    putHTMLheader("hello");
    printf("Hello World\n");
    putHTMLfooter();
    return 0;
}
