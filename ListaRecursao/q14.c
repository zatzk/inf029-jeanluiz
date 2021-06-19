#include <stdio.h>

int imprimir(int num, int y){
    int aux = num % 2;
    if(num > 0){
        if(aux == 0){
            printf("%d ", y);
            imprimir(num-2, y+2);
        }
        else if(aux > 0){
            printf("Impar, erro");
            return 0;
        }
    }
    else{
        return 0;
    }
}

int main(){
    int n, y=0;
    printf("insira N\n");
    scanf("%d", &n);
    imprimir(n, y);
}