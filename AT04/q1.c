#include <stdio.h>
#include <stdlib.h>

int soma();


int main(){

    int v1, v2, resultado;

    printf("Digite os valores a serem somados: ");
    scanf("%d %d", &v1, &v2);

    resultado = soma(v1, v2);

    printf("resultado: %d", resultado);
}

int soma(int n1, int n2){
    int r;

    r = n1*n2;

    return r;
}