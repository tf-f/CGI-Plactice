#include <stdio.h>
#include "myhtml.h"
#include <math.h>
#define MAX 2000000
#define S 10000

int arr[MAX] = { 0 };

void Eratosthenes(int N){
    int i,j;
    for(i = 0; i < N; i++){
        arr[i] = 1;
    }
    
    for(i = 2; i < sqrt(N); i++){
        if(arr[i]){
	    for(j = 0; i * ( j + 2 ) < N; j++){
	        arr[i * ( j + 2)] = 0;
            }
	}
    }
    int cn;
    cn = 0;
    for(i = 2; i < N; i++){
        if(arr[i] && cn <= 100){
	    printf("%d\n",i);
	    cn++;
	}
    }
}

int main(){
    putContentType();
    putHTMLheader("Prime Number");
    Eratosthenes(S);

    putHTMLfooter();
    return 0;
}
