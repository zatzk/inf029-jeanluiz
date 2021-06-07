#include <stdio.h>

// Funcao recursiva que recebe um inteiro n >= 1
// devolve o n-esimo termo da sequencia de Fibonacci.

int fibonacci(int n){
    if(n==0){
        return 0;
    } 
    else if(n==1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    } 
}

int main(){
    int num = 8;
    printf("%d", fibonacci(num));
}