#include <stdio.h>
#include <stdlib.h>

struct passagem_dados{
    char letras[4];

};

struct passagem_dados passagem;

int ler3letras();

int ler3letras(){  
    printf("Entre com 3 letras do array : ");   
    fgets(passagem.letras, 4, stdin);  
    
}  
int main(){
    ler3letras();
    printf("\nResultado :");  
    printf("%s", passagem.letras);  
   
}  