#include <stdio.h>
#include <string.h>
#include "myhtml.h"

int main(){
    char buf[256],uid[80];
    int age,male;
    char* ptr;

    fgets(buf,sizeof(buf),stdin);
    putContentType();
    putHTMLheader("POST value\n");
    puts(buf);
   
    putHTMLfooter();
    return 0;
}
