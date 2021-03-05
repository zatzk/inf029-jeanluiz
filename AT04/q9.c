#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastrar{
    char nome[20];
    int dd,mm,aa;
    int cpf;
    char sexo[20];
};

int cadastrarCliente();
int cNome();
int cSexo();
int cCPF();
int cNasc();

void limparBuffer();

struct cadastrar cadastro;
    
int main(){
    cadastrarCliente();
    

    printf("\n__Dados cadastrados__\n");
    printf("Nome: %s\n", cadastro.nome);
    printf("CPF: %d\n", cadastro.cpf);
    printf("Sexo: %s\n", cadastro.sexo);
    printf("Nascimento: %d/%d/%d", cadastro.dd,cadastro.mm,cadastro.aa);
}

void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}


int cadastrarCliente(){
    system("clear || cls");
    int v=0;
    while(v!=1){
        printf("Deseja realizar cadastro?\n ");
        printf("1 - Sim\nOutro - Nao\n ");
        scanf("%d", &v);
        limparBuffer();
        if(v==1){
            cNome();
        }
        else{
            system("clear || cls");
            printf("\nReiniciando tela de cadastro");
        }
    }
    v=0;
    

    
}

int cNome(){
    system("clear || cls");
    printf("Digite seu nome: \n");
    scanf("%s", &cadastro.nome);
    limparBuffer();
    cSexo();
}

int cSexo(){
    system("clear || cls");
    int s;
    printf("Digite seu sexo: \n");
    printf("\n1 - masculino\n2 - feminino\n3 - Outro\n");
	scanf("%d", &s);
    limparBuffer();
    if(s==1){
        strcpy(cadastro.sexo,"Masculino");
        cCPF();
    }
    else if(s==2){
        strcpy(cadastro.sexo,"Feminino");
        cCPF();
    }
    else if(s==3){
        strcpy(cadastro.sexo,"Outro");
        cCPF();
    }
    else{
        printf("opcao invalida! ");
        cadastrarCliente();
    }
        
}

int cCPF(){
    system("clear || cls");
    printf("Insira o CPF: ");
    scanf("%d", &cadastro.cpf);
    limparBuffer();
    if(cadastro.cpf>99999999999 || cadastro.cpf<0){
        printf("CPF Invalido!");
        cadastrarCliente();
    }
    if(cadastro.cpf<=99999999999){
        printf("CPF Valido!\n");
        cNasc();
    }
    

}
int cNasc(){
    system("clear || cls");
    int dia, mes, ano, nasc;
    printf("Digite nascimento\n\n");
    printf("Digite o dia: \n");
    scanf("%d", &dia);
    cadastro.dd = dia;
    printf("Digite o mes: \n");
    scanf("%d", &mes);
    cadastro.mm = mes;
    printf("Digite o ano: \n");
    scanf("%d", &ano);
    limparBuffer();
    cadastro.aa = ano;

    mes = mes*30;
    ano = ano*365;
    nasc = dia+mes+ano;

    if(nasc<730865){
        printf("maior de idade!");
        return 0;
        
    }
    else{
        printf("menor de idade!");
        cadastrarCliente();
    }
    
}