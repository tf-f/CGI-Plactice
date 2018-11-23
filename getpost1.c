#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myhtml.h"

int main(){
    char buf[256],uid[80],age,male;
    int len;
    char* query;
//    char* method;
    char* ptr; 
  //  char* env; 
    
    putContentType();
    ptr = getenv("REQUEST_METHOD");
    if(strcmp(ptr,"GET") == 0){
        putHTMLheader("GET Value");
	ptr = getenv("QUERY_STRING");
	len = strlen(ptr);
	query = (char*)malloc(len+1);
	strncpy(query,ptr,len+1);
	//strncpy(buf,env,sizeof(buf));

    }else{
        putHTMLheader("POST Value");
        ptr = getenv("CONTENT_LENGTH");
	len = atoi(ptr);
	query=(char*)malloc(len+1);
	fgets(query,len+1,stdin);
	//fgets(buf,sizeof(buf),stdin);
    }
    
    //strncpy(buf,query,sizeof(buf));
    //strncpy(uid,ptr,sizeof(buf));
    
    
    ptr = strtok(query,"=");
    ptr = strtok(NULL,"&");
    strncpy(uid,ptr,sizeof(uid));
    
    ptr =strtok(NULL, "=");
    ptr = strtok(NULL,"&");
    male = atoi(ptr);
    ptr = strtok(NULL, "=");
    ptr = strtok(NULL,"&");
    age = atoi(ptr);
    
    printf("Your Name: %s <br>", uid);
    puts("Gender: ");
    if(male==0){
        printf("fe");
    }
    puts("male<br>");
    
    puts("Age: ");
    switch(age){
    case 1: puts("10è¢∑19"); break;
    case 2: puts("20è¢∑29"); break;
    case 3: puts("30è¢∑"); break;
    default: break;
    }
    puts("<br>");
    putHTMLfooter();
    
   // free (query);
    return 0;
}
