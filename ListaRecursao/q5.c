#include <stdio.h>
#include <stdlib.h>


int somatorio(int n){
    int s;
    if(n==0){
        return 0;
    }
    else{
        s = (n + somatorio(n-1));
    }
    return s;
}

int main(){
    int num = 5;
    printf("%d", somatorio(num));
}