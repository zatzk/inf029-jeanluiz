#include <stdio.h>
#include <stdlib.h>

int *ler3numeros();

int *ler3numeros(int *a){  
    
    printf("Entre com 3 numeros do array : ");  
    for(int i=0;i<3;i++){  
        scanf("%d", &a[i]);  
    }  
    return a;  
}  
int main(){  
  int *n;  
  int a[3];  
  n=ler3numeros(a);  
  printf("\nResultado :");  
  for(int i=0;i<3;i++){  
        printf("%d", n[i]);  
    }  
    return 0;  
}  