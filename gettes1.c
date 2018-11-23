#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myhtml.h"

int main(){
    char buf[256],uid[80];
    int age,male;
    char* ptr;
    char* env;
    env = getenv("QUERY_STRING");
    strncpy(buf,env,sizeof(buf));
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

    putHTMLheader("GET Value\n");
    
    printf("Your Name: %s <br>", uid);
    
    puts("Gender: ");
    if(male==0){
        printf("fe");
    }
    puts("male<br>");
    
    puts("Age: ");
    switch(age){
    case 1: puts("10¡Á19"); break;
    case 2: puts("20¡Á29"); break;
    case 3: puts("30¡Á"); break;
    default: break;
    }
    puts("<br>");
    putHTMLfooter();
    return 0;
}
