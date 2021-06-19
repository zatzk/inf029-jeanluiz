#include <stdio.h>

int somat(int num){
    if(num < 1){
        return 0;
    }
    else{
        return num + somat(num-1);
    }
}

int main(){
    int n;
    printf("insira N\n");
    scanf("%d", &n);
    printf("%d", somat(n));
}