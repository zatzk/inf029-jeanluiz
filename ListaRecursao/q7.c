#include <stdio.h>
#define SIZE 10

int inverter(int v[], int inicio, int fim){
    int aux;
    if(inicio < fim){
        aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
        inverter(v, inicio + 1, fim - 1);
    }

}
void imprimir(int v[], int tam){
    if(tam == 1){
        printf("%d, ",  v[tam-1]);
    }
    else{
        imprimir(v, tam - 1);
        printf("%d, ",  v[tam-1]);
    }
}

int main(){
    int v[SIZE];
    printf("preencha o vetor\n");
    for(int i = 0; i < SIZE; i ++){
        scanf("%d", &v[i]);
        printf("posicao %d = %d\n", i+1, v[i]);
    }

    int inicio = 0;
    int fim = SIZE;
    inverter(v, inicio, fim);
    imprimir(v, fim);
}