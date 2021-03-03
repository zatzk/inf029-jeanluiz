#include <stdio.h>
#include <stdlib.h>

struct passagem_dados{
    char palavras[3][20];

};

struct passagem_dados passagem;

int ler3palavras();

int ler3palavras(){  
    printf("Entre com 3 palavras do array : ");   
    for (int i = 0; i < 3; i++){
        scanf("%s", passagem.palavras[i]); 
    }
    
    
}  
int main(){
    ler3palavras();
    printf("\nResultado:\n");  
    for (int i = 0; i < 3; i++){
        printf("%s\n", passagem.palavras[i]); 
    }
   
}  