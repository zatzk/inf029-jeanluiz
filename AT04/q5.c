#include <stdio.h>
#include <stdlib.h>

struct passagem_dados{
    int numbers[4];

};

struct passagem_dados passagem;

int ler4numeros();

int ler4numeros(){  
    printf("Entre com 4 numeros do array : ");  
    for(int i=0;i<4;i++){  
        scanf("%d", &passagem.numbers[i]);  
    }  
    
}  
int main(){
    ler4numeros();
    printf("\nResultado :");  
  for(int i=0;i<4;i++){  
        printf("%d", passagem.numbers[i]);  
    } 
   
}  