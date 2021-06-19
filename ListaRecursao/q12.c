#include <stdio.h>

int imprimir(int num, int y){
    if(num < 1){
        return 0;
    }
    else{
        printf("%d", y);
        imprimir(num-1, y+1);
    }
}

int main(){
    int n, y=0;
    printf("insira N\n");
    scanf("%d", &n);
    imprimir(n, y);
}