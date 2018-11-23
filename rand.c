#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"myhtml.h"

int main(){
    int num;
    srand((unsigned int)time(NULL));
    num = rand();

    putContentType();
    putHTMLheader("Rand_Game");
    



    putHTMLfooter();
    return 0;
}
