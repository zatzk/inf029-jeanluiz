#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastrar{
    char nome[20];
    int dataNascimento;
    int cpf;
    char sexo[20];
};

void cadastrarCliente();

struct cadastrar cadastro;
    
int main(){
    cadastrarCliente();
    system("clear || cls");

    printf("__Dados cadastrados__\n");
    printf("Nome: %s\n", cadastro.nome);
    printf("Data de nascimento (8 digitos): %d\n", cadastro.dataNascimento);
    printf("CPF (5 digitos):%d\n", cadastro.cpf);
    printf("Sexo: %s\n", cadastro.sexo);

}

void cadastrarCliente(){
    int v;
    printf("Digite os dados:\n");
    printf("Nome:");
    scanf("%s", &cadastro.nome);
    printf("\nData de nascimento (8 digitos):");
    scanf("%d", &cadastro.dataNascimento);
    printf("\nCPF (5 digitos):");
    scanf("%d", &cadastro.cpf);
    printf("\nDigite 1 para masculino e 2 para feminino");
    scanf("%d", &v);
    if(v==1){
        strcpy(cadastro.sexo,"masculino");
    }
    else if(v==2){
        strcpy(cadastro.sexo,"feminino");
    }
    else{
        strcpy(cadastro.sexo,"Outro");
    }
}