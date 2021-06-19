#include <stdio.h>

int imprimir(int num){
    if(num < 1){
        return 0;
    }
    else{
        printf("%d", num);
        imprimir(num-1);
    }
}

int main(){
    int n;
    printf("insira N\n");
    scanf("%d", &n);
    imprimir(n);
}