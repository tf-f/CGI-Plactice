#include <stdio.h>
#include <string.h>
#include "myhtml.h"

int main(){
    char buf[256],uid[80];
    int age,male;
    char* ptr;

    fgets(buf,sizeof(buf),stdin);
    putContentType();
    ptr = strtok(buf,"=");
    ptr = strtok(NULL,"&");
    strncpy(uid,ptr,sizeof(uid));

    ptr =strtok(NULL, "=");
    ptr = strtok(NULL,"&");
    male = atoi(ptr);
    ptr = strtok(NULL, "=");
    ptr = strtok(NULL,"&");
    age = atoi(ptr);

    putHTMLheader("POST value\n");
    
    printf("Your Name:%s <br>", uid);
    
    puts("Gender:");
    if(male==0){
        printf("fe");
    }
    puts("male<br>");
    
    puts("Age:");
    switch(age){
    case 1: puts("10��19"); break;
    case 2: puts("20��29"); break;
    case 3: puts("30��"); break;
    default: break;
    }
    puts("<br>");
    putHTMLfooter();
    return 0;
}
