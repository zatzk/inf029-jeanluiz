#include <stdio.h>
#include <stdlib.h>

int main(){

    int select;
    int calc, som1,som2, mult1, mult2, sub1, sub2, div1, div2;

    printf("Escolha uma opcao: \n1 - Somar\n2 - Multiplicar\n3 - Subtrair\n4 - Dividir\n0 - Sair\n\n");
    scanf("%d", &select);

    switch(select){

        case 1:
        printf("Digite os valores a serem somados: ");
        scanf("%d %d", &som1, &som2);
        calc = som1+som2;
        printf("Resultado: %d",  calc);
        break;

        case 2:
        printf("Digite os valores a serem multiplicados: ");
        scanf("%d %d", &mult1, &mult2);
        calc = mult1*mult2;
        printf("Resultado: %d",  calc);
        break;

        case 3:
        printf("Digite os valores a serem subtraidos: ");
        scanf("%d %d", &sub1, &sub2);
        calc = sub1-sub2;
        printf("Resultado: %d",  calc);
        break;

        case 4:
        printf("Digite os valores a serem divididos: ");
        scanf("%d %d", &div1, &div2);
        calc = div1-div2;
        printf("Resultado: %d",  calc);
        break;

        case 0:
        break;
    }

}