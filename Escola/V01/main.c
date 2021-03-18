#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "limparbuffer.h"


#define MAX 10


struct aluno{
    char nome[20], cpf[14], sexo[10], matricula[20];
	char disciplina[20],codigo[14]; 
    int dia,mes,ano,semestre;
	int al_ativo, al_inserido;
};
struct professor{
    char nome[20], cpf[14], sexo[10], matricula[20];
	char disciplina[20],codigo[14]; 
    int dia,mes,ano,semestre;
	int pf_ativo, pf_inserido;
};
struct disciplina{
    char disciplina[20],codigo[14];
    int semestre;
	int disc_ativo;
};

struct aluno alunoCad[MAX];
struct professor professorCad[MAX];
struct disciplina disciplinaCad[MAX];

void cadastrosMenu();
void cadastrarAluno();
void cadastrarProfessor();
void cadastrarDisciplina();

void inserirMenu();
void inserirAluno();
void inserirProfessor();

void removerMenu();
void removerAluno();
void removerProfessor();
void removerDisciplina();
void removerDisciplinaAluno();
void removerDisciplinaProfessor();


void limparBuffer();

int main(){
    int op;
	do{
		system("clear || cls");
        printf("\n______Sistema Escolar_____\n\n");

		printf("\n1 - Cadastrar");
		printf("\n2 - Remover");
		printf("\n3 - inserir");
        printf("\n4 - Listas");
        printf("\n0 - Sair");
		scanf("%d", &op);
		limparBuffer();

		switch(op){
			case 1:
				cadastrosMenu();
			break;
			case 2:
				removerMenu();
			break;
			case 3:
				inserirMenu();
			break;
			/*case 4: 
				listagensMenu();
			break;*/
		}
	}while(op!=0);
}

void cadastrosMenu(){
    int op;
    do{
        system("clear || cls");
        printf("\n1 - Cadastrar Aluno");
        printf("\n2 - Cadastrar Professor");
        printf("\n3 - Cadastrar Disciplina");
        printf("\n0 - Sair\n");
        scanf("%d", &op);
        limparBuffer();
        switch(op){
            case 1:
                cadastrarAluno();
            break;
            case 2:
                cadastrarProfessor();
            break;
            case 3:
                cadastrarDisciplina();
            break;
        }
    } while (op!=0);

}
void cadastrarAluno(){
    
    char nome[20],cpf[14], sexo[10], matricula[20];
    int dia,mes,ano;
	int op,i;
    int sx;


    do{
        system("clear || cls");
        printf("\nNome: ");
		fgets(nome, sizeof(nome), stdin);
        limparBuffer();
        printf("\nMatricula: ");
		fgets(matricula, sizeof(matricula), stdin);
        limparBuffer();
        printf("\nCPF: ");
		fgets(cpf, sizeof(cpf), stdin);
        limparBuffer();
        printf("\nSexo: ");
        printf("\n1 - Masculino\n2 - Feminino\n3 - Outro");
        scanf("%d", &sx);
        limparBuffer();
        if(sx == 1){
            strcpy(sexo, "Masculino");
        }
        if(sx == 2){
            strcpy(sexo, "Feminino");
        }
        if(sx == 3){
            strcpy(sexo, "Outro");
        }
        printf("\nData de nascimento\n");
        printf("\nDia: ");
        scanf("%d", &dia);
        limparBuffer();
        printf("\nMes: ");
        scanf("%d", &mes);
        limparBuffer();
        printf("\nAno: ");
        scanf("%d", &ano);
        limparBuffer();

        for(i = 0; i < MAX; i++){
			if(alunoCad[i].al_ativo != 1){
				strcpy(alunoCad[i].cpf, cpf);
				strcpy(alunoCad[i].matricula, matricula);
				strcpy(alunoCad[i].nome, nome);
				strcpy(alunoCad[i].sexo, sexo);
                alunoCad[i].dia=dia;
                alunoCad[i].mes=mes;
                alunoCad[i].ano=ano;
				alunoCad[i].al_ativo=1;
				break;
			}
		}

        printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &op);
        limparBuffer();
    }while(op!=0);



}
void cadastrarProfessor(){
    
    char nome[20],cpf[14], sexo[10], matricula[20];
    int dia,mes,ano;
	int op,i;
    int sx;


    do{
        system("clear || cls");
        printf("\nNome: ");
		fgets(nome, sizeof(nome), stdin);
        limparBuffer();
        printf("\nMatricula: ");
		fgets(matricula, sizeof(matricula), stdin);
        limparBuffer();
        printf("\nCPF: ");
		fgets(cpf, sizeof(cpf), stdin);
        limparBuffer();
        printf("\nSexo: ");
        printf("\n1 - Masculino\n2 - Feminino\n3 - Outro");
        scanf("%d", &sx);
        limparBuffer();
        if(sx == 1){
            strcpy(sexo, "Masculino");
        }
        if(sx == 2){
            strcpy(sexo, "Feminino");
        }
        if(sx == 3){
            strcpy(sexo, "Outro");
        }
        printf("\nData de nascimento\n");
        printf("\nDia: ");
        scanf("%d", &dia);
        limparBuffer();
        printf("\nMes: ");
        scanf("%d", &mes);
        limparBuffer();
        printf("\nAno: ");
        scanf("%d", &ano);
        limparBuffer();

        for(i = 0; i < MAX; i++){
			if(professorCad[i].pf_ativo != 1){
				strcpy(professorCad[i].cpf, cpf);
				strcpy(professorCad[i].matricula, matricula);
				strcpy(professorCad[i].nome, nome);
				strcpy(professorCad[i].sexo, sexo);
                professorCad[i].dia=dia;
                professorCad[i].mes=mes;
                professorCad[i].ano=ano;
				professorCad[i].pf_ativo=1;
				break;
			}
		}

        printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &op);
        limparBuffer();
    }while(op!=0);
}




void cadastrarDisciplina(){
    
    char disciplina[20],codigo[14];
    int semestre;
    int op,i;
    do{
		system("clear || cls");
        printf("\nDisciplina: ");
        fgets(disciplina, sizeof(disciplina), stdin);
        limparBuffer();
        printf("\nCodigo: ");
        fgets(codigo, sizeof(codigo), stdin);
        printf("\nSemestre: ");
        scanf("%d", &semestre);
        for(i=0;i<MAX;i++){
			if(disciplinaCad[i].disc_ativo != 1){
				strcpy(disciplinaCad[i].disciplina, disciplina);
				strcpy(disciplinaCad[i].codigo, codigo);
                disciplinaCad[i].semestre=semestre;
				disciplinaCad[i].disc_ativo=1;
				break;
			}
		}
        printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
    }while(op!=0);

}


void inserirMenu(){
	int op;
	do{
		system("clear || cls");
		printf("\n1 - Inserir Aluno em disciplina");
		printf("\n2 - Inserir Professor em disciplina");
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
		switch(op){
			case 1:
				inserirAluno();
			break;
			case 2:
				inserirProfessor();
			break;
		}
	}while(op!=0);
}

void inserirAluno(){
	int op,i;
	char matricula[20], codigo[14];
	do{
		system("clear || cls");
		printf("\nDigite a Matricula do aluno: ");
		fgets(matricula, sizeof(matricula), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(alunoCad[i].matricula, matricula)!=NULL){
				printf("Pois bem %s\n", alunoCad[i].nome);
			}
		}
		printf("\nDigite o codigo da disciplina: ");
		fgets(codigo, sizeof(codigo), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(alunoCad[i].matricula, matricula)!=NULL){
				if(strstr(disciplinaCad[i].codigo, codigo)!=NULL){
					if(alunoCad[i].al_inserido==0){
						strcpy(alunoCad[i].disciplina, disciplinaCad[i].disciplina);
						strcpy(alunoCad[i].codigo, disciplinaCad[i].codigo);
						alunoCad[i].semestre=disciplinaCad[i].semestre;
						alunoCad[i].al_inserido=1;
						printf("\nDisciplina Inserida");
						break;	
					}
				}
			}
		}
		printf("\n1 - Inserir outra\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}

void inserirProfessor(){
	char matricula[20], codigo[14];
	int op,i;
	do{
		system("clear || cls");
		printf("\nDigite a Matricula do professor: ");
		fgets(matricula, sizeof(matricula), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(professorCad[i].matricula, matricula)!=NULL){
				printf("Pois bem %s\n", professorCad[i].nome);
			}
		}
		printf("\nDigite o codigo da disciplina: ");
		fgets(codigo, sizeof(codigo), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(professorCad[i].matricula, matricula)!=NULL){
				if(strstr(disciplinaCad[i].codigo, codigo)!=NULL){
					if(professorCad[i].pf_inserido==0){
						strcpy(professorCad[i].disciplina, disciplinaCad[i].disciplina);
						strcpy(professorCad[i].codigo, disciplinaCad[i].codigo);
						professorCad[i].semestre=disciplinaCad[i].semestre;
						professorCad[i].pf_inserido=1;
						printf("\nDisciplina Inserida");
						break;
					}
				}
			}
		}
		printf("\n1 - Inserir outra\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);

}

void removerMenu(){
    int op;
    do{
		system("clear || cls");
        printf("\n1 - Remover Aluno");
        printf("\n2 - Remover Professor");
        printf("\n3 - Remover Disciplina");
        printf("\n4 - Remover Disciplina do cadastro do aluno");
        printf("\n5 - Remover Disciplina do cadastro do professor");
        printf("\n0 - Sair");
        scanf("%d", &op);
		limparBuffer();
        switch(op){
            case 1:
                removerAluno();
            break;
            case 2:
                removerProfessor();
            break;
            case 3:
                removerDisciplina();
            break;
            case 4:
                removerDisciplinaAluno();
            break;
            case 5:
                removerDisciplinaProfessor();
            break;
        }
    }while(op!=0);
}
void removerAluno(){
	system("clear || cls");
	char matricula[20];
	int i,op;
	do{
		printf("\nDigite a Matricula do aluno a ser removido: ");
		fgets(matricula, sizeof(matricula), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(alunoCad[i].al_ativo==1){
				if(strstr(alunoCad[i].matricula, matricula)!=NULL){
					printf("Nome: %s\n", alunoCad[i].nome);
					printf("CPF: %s\n", alunoCad[i].cpf);
					printf("Matricula: %s\n", alunoCad[i].matricula);
					printf("\n----------------\n");	
					alunoCad[i].al_ativo=0;
					printf("Matricula removida com sucesso\n");
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}

//remover professor do sistema
void removerProfessor(){
	system("clear || cls");
	char matricula[20];
	int i,op;
	do{
		printf("\nDigite a Matricula do professor a ser removido: ");
		fgets(matricula, sizeof(matricula), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(professorCad[i].pf_ativo==1){
				if(strstr(professorCad[i].matricula, matricula)!=NULL){
					printf("Nome: %s\n", professorCad[i].nome);
					printf("CPF: %s\n", professorCad[i].cpf);
					printf("Matricula: %s\n", professorCad[i].matricula);
					printf("\n----------------\n");	
					professorCad[i].pf_ativo=0;
					printf("Matricula removida com sucesso\n");
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}

//remover disciplina do sistema
void removerDisciplina(){
	system("clear || cls");
	char codigo[14];
	int i,op;
	do{
		printf("\nDigite o codigo da disciplina a ser removida: ");
		fgets(codigo, sizeof(codigo), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(disciplinaCad[i].disc_ativo==1){
				if(strstr(disciplinaCad[i].codigo, codigo)!=NULL){
					printf("Disciplina: %s\n", disciplinaCad[i].disciplina);
					printf("codigo: %s\n", disciplinaCad[i].codigo);
					printf("Semestre: %d\n", disciplinaCad[i].semestre);
					printf("\n----------------\n");	
					disciplinaCad[i].disc_ativo=0;
					printf("Disciplina removida com sucesso\n");
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}

//remove alguma disciplina registrada em algum aluno
void removerDisciplinaAluno(){
	system("clear || cls");
	char codigo[14],matricula[20];
	int i,op;
	do{
		printf("\nDigite a Matricula do aluno que terá uma disciplina removida: ");
		fgets(matricula, sizeof(matricula), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(alunoCad[i].al_inserido==1){
				if(strstr(alunoCad[i].matricula, matricula)!=NULL){
					printf("Nome: %s\n", alunoCad[i].nome);
					printf("CPF: %s\n", alunoCad[i].cpf);
					printf("Matricula: %s\n", alunoCad[i].matricula);
					printf("Disciplina: %s\n", disciplinaCad[i].disciplina);
					printf("codigo: %s\n", disciplinaCad[i].codigo);
					printf("Semestre: %d\n", disciplinaCad[i].semestre);
					printf("\n----------------\n");	
					alunoCad[i].al_inserido=0;
					printf("Disciplina removida do cadastro do aluno com sucesso\n");
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}

//remove alguma disciplina registrada em algum professor
void removerDisciplinaProfessor(){
	system("clear || cls");
	char codigo[14],matricula[20];
	int i,op;
	do{
		printf("\nDigite a Matricula do professor que terá uma disciplina removida: ");
		fgets(matricula, sizeof(matricula), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(professorCad[i].pf_inserido==1){
				if(strstr(professorCad[i].matricula, matricula)!=NULL){
					printf("Nome: %s\n", professorCad[i].nome);
					printf("CPF: %s\n", professorCad[i].cpf);
					printf("Matricula: %s\n", professorCad[i].matricula);
					printf("Disciplina: %s\n", disciplinaCad[i].disciplina);
					printf("codigo: %s\n", disciplinaCad[i].codigo);
					printf("Semestre: %d\n", disciplinaCad[i].semestre);
					printf("\n----------------\n");	
					professorCad[i].pf_inserido=0;
					printf("Disciplina removida do cadastro do professor com sucesso\n");
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}