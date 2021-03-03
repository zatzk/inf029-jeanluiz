#include <stdio.h>
#include <stdlib.h>

int fatorial();


int main(){

    int v1, resultado;

    printf("Digite os valor: ");
    scanf("%d", &v1);
    
    if(v1 <= 0){
        printf("Impossivel calcular fatorial: ");

        return 0;
    }

    else{
        resultado = fatorial(v1);
        printf("resultado: %d", resultado);

    }
    
}

int fatorial(int n1){
    int r=1, i;
    for (i = 1; i <= n1; ++i) {
            r *=i;
    }
    return r;
}