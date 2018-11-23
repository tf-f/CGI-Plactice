#include <stdio.h>
#include "myhtml.h"

#define COUNTER "count.txt"

int main(){
    int c;
    char buf[256];
    FILE* fp;

    putContentType();
    putHTMLheader("Counter");
    fp = fopen(COUNTER,"rt");
    if(fp == NULL) return 1;
    fgets(buf, sizeof(buf),fp);
    fclose(fp);

    c = atoi(buf);
    c++;
    if(c > 2147483646) c = 0;
    printf("%d\n",c);

    fp = fopen(COUNTER,"wt");
    if(fp == NULL) return 1;
    fprintf(fp,"%d\n",c);
    fclose(fp);
    
    putHTMLfooter();

    return 0;
}
