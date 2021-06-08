#include <stdio.h>

int potencia(int base, int expoente){
     if(expoente == 0){
         return 1;
     }
        
    else{
        return(base * potencia(base, expoente-1));
    }

}
int main(){
    int k,n;
    printf("digite os valores de k e n\n");
    scanf("%d", &k);
    scanf("%d", &n);
    printf("%d elevado a %d = %d", k, n, potencia(k, n));
}