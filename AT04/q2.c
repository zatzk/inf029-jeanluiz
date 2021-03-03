#include <stdio.h>
#include <stdlib.h>

int subtrair();


int main(){

    int v1, v2, v3, resultado;

    printf("Digite os valores a serem subtraidos: ");
    scanf("%d %d %d", &v1, &v2, &v3);

    resultado = subtrair(v1, v2, v3);

    printf("resultado: %d", resultado);
}

int subtrair(int n1, int n2, int n3){
    int r;

    r = (n1-n2)-n3;

    return r;
}