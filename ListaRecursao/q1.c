#include <stdio.h>
#include <stdlib.h>


int fatorial(int n){
    if((n==1) || (n==0)){
        return 1;
    }
    else{
        n = (n * fatorial(n-1));
    }
    
}

int main(){
    int num = 10;
    printf("%d", fatorial(num));
}