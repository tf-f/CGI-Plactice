#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myhtml.h"

int main(){
    char buf[256],uid[80],age,male;
    int len,get=0;
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
	get = 1;
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
    
    while (ptr != NULL) {
        if (strncmp(ptr, "uid", 3) == 0) {   /* uid */
            ptr = strtok(NULL, "&");
            if (ptr != NULL){	
                strncpy(uid, ptr, sizeof(uid));
            }else{
                strcpy(uid, "noname");
	    }
        } else if (strncmp(ptr, "male", 4) == 0) { /* male */
            ptr = strtok(NULL, "&");
            if (ptr != NULL){
	        male = atoi(ptr);
	    }else{
	        male = -1;
	    }
        } else if (strncmp(ptr, "age", 3) == 0) { /* age */
	    ptr = strtok(NULL, "&");
	    if (ptr != NULL){
	        age = atoi(ptr);
            }else{
	        age = -1;
	    }
	} else { /* other keywords */
	    ptr = strtok(NULL, "&");
        }
        if (ptr != NULL) ptr = strtok(NULL, "=");
    }
    
    printf("<p>Method is  %s \n", get==1 ? "GET":"POST");
    
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
    
   // free (query);
    return 0;
}
