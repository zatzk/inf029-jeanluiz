#include <stdio.h>

int imprimir(int num){
    int aux = num % 2;
    if(num > 0){
        if(aux == 0){
            printf("%d ", num);
            imprimir(num-2);
        }
        else if(aux > 0){
            printf("Impar, Erro");
            return 0;
        }
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    printf("insira N\n");
    scanf("%d", &n);
    imprimir(n);
}