#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "limparbuffer.h"


#define MAX 40


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

void listagensMenu();
void listarAluno();
void listarProfessor();
void listarDisciplina();
void listarDadosDisciplina();
void listarAlunoSexo();
void listarProfessorSexo();
void listarAniversariantes();
void listarAlunoNome();
void listarProfessorNome();

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
        printf("\n0 - Sair\n");
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
			case 4: 
				listagensMenu();
			break;
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
    int sx, m;


    do{
        system("clear || cls");
        printf("\nNome: ");
		fgets(nome, sizeof(nome), stdin);
        limparBuffer();
        printf("\nMatricula: ");
		fgets(matricula, sizeof(matricula), stdin);
        limparBuffer();

		for(i=0;i<MAX;i++){
			if(strstr(alunoCad[i].matricula, matricula)!=NULL){
				printf("\nMatricula ja cadastrada");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}
        printf("\nCPF: ");
		fgets(cpf, sizeof(cpf), stdin);
        limparBuffer();
		
		for(i=0;i<MAX;i++){
			if(strstr(alunoCad[i].cpf, cpf)!=NULL){
				printf("\nCPF ja cadastrado");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}

        printf("\nSexo: ");
        printf("\n1 - Masculino\n2 - Feminino\n3 - Outro\n");
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
        printf("\nData de nascimento");
        printf("\nDia: ");
        scanf("%d", &dia);
        limparBuffer();
        printf("\nMes: ");
        scanf("%d", &mes);
        limparBuffer();
        printf("\nAno: ");
        scanf("%d", &ano);
        limparBuffer();
		if((ano < 1950)||(ano > 2003)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			if(m==1){
				return;
			}
		}

		if((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12) && (dia > 31) || (dia < 1)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			limparBuffer();
			if(m==1){
				return;
			}
		}
		if((mes==2) && (dia > 28)|| (dia < 1)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			limparBuffer();
			if(m==1){
				return;
			}
		}
		if((mes==2) && (dia ==29)){
			if(ano%4!=0 && (ano%100==0 || ano%400!=0)){
				printf("Data invalida");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}
		
		if((mes==4)||(mes==6)||(mes==9)||(mes==11) && (dia > 30)|| (dia < 1)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			limparBuffer();
			if(m==1){
				return;
			}
		}



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
    int sx,m;


    do{
        system("clear || cls");
        printf("\nNome: ");
		fgets(nome, sizeof(nome), stdin);
        limparBuffer();
        printf("\nMatricula: ");
		fgets(matricula, sizeof(matricula), stdin);
        limparBuffer();

		for(i=0;i<MAX;i++){
			if(strstr(professorCad[i].matricula, matricula)!=NULL){
				printf("\nMatricula ja cadastrada");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}

        printf("\nCPF: ");
		fgets(cpf, sizeof(cpf), stdin);
        limparBuffer();

		for(i=0;i<MAX;i++){
			if(strstr(professorCad[i].cpf, cpf)!=NULL){
				printf("\nCPF ja cadastrado");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}

        printf("\nSexo: ");
        printf("\n1 - Masculino\n2 - Feminino\n3 - Outro\n");
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
        printf("\nData de nascimento");
        printf("\nDia: ");
        scanf("%d", &dia);
        limparBuffer();
        printf("\nMes: ");
        scanf("%d", &mes);
        limparBuffer();
        printf("\nAno: ");
        scanf("%d", &ano);
        limparBuffer();

		if((ano < 1950)||(ano > 2003)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			if(m==1){
				return;
			}
		}

		if((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12) && (dia > 31)|| (dia < 1)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			limparBuffer();
			if(m==1){
				return;
			}
		}
		if((mes==2) && (dia > 28)|| (dia < 1)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			limparBuffer();
			if(m==1){
				return;
			}
		}
		if((mes==2) && (dia ==29)){
			if(ano%4!=0 && (ano%100==0 || ano%400!=0)){
				printf("Data invalida");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}
		if((mes==4)||(mes==6)||(mes==9)||(mes==11) && (dia > 30)|| (dia < 1)){
			printf("Data invalida");
			printf("\nPressione 1 para sair\n");
			scanf("%d", &m);
			limparBuffer();
			if(m==1){
				return;
			}
		}

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
    int op,i,m;
    do{
		system("clear || cls");
        printf("\nDisciplina: ");
        fgets(disciplina, sizeof(disciplina), stdin);
        limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(disciplinaCad[i].disciplina, disciplina)!=NULL){
				printf("\nDisciplina ja cadastrada");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}


        printf("\nCodigo: ");
        fgets(codigo, sizeof(codigo), stdin);
		limparBuffer();

		for(i=0;i<MAX;i++){
			if(strstr(disciplinaCad[i].codigo, codigo)!=NULL){
				printf("\nCodigo ja cadastrado");
				printf("\nPressione 1 para sair\n");
				scanf("%d", &m);
				limparBuffer();
				if(m==1){
					return;
				}
			}
		}



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
					if(alunoCad[i].al_inserido!=1){
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
					if(professorCad[i].pf_inserido!=1){
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
        printf("\n0 - Sair\n");
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

void listagensMenu(){
	int op;
    do{
        system("clear || cls");
        printf("\n1 -  Listar Alunos");
        printf("\n2 -  Listar Professores");
        printf("\n3 -  Listar Disciplinas");
        printf("\n4 -  Listar Dados de uma Disciplina");
        printf("\n5 -  Listar Alunos por Sexo");
        printf("\n6 -  Listar Professores por Sexo");
        printf("\n7 -  Listar Aniversariantes");
        printf("\n8 -  Listar Alunos por nome");
        printf("\n9 -  Listar Professores por nome");
        printf("\n0 - Sair\n");
        scanf("%d", &op);
        limparBuffer();
        switch(op){
            case 1:
                listarAluno();
            break;
            case 2:
                listarProfessor();
            break;
            case 3:
                listarDisciplina();
            break;
            case 4:
                listarDadosDisciplina();
            break;
            case 5:
                listarAlunoSexo();
            break;
            case 6:
                listarProfessorSexo();
            break;
            case 7:
                listarAniversariantes();
            break;
            case 8:
                listarAlunoNome();
            break;
            case 9:
                listarProfessorNome();
            break;
        }
    }while (op!=0);
}

void listarAluno(){
    int i,op;

	do{
		system("clear || cls");
		printf("_____LISTA DE ALUNOS_____\n");
		for(i=0;i<MAX;i++){
			if(alunoCad[i].al_ativo==1){
				printf("Nome: %s\n", alunoCad[i].nome);
				printf("Matricula: %s\n", alunoCad[i].matricula);
				printf("CPF: %s\n", alunoCad[i].cpf);
				printf("Sexo: %s\n", alunoCad[i].sexo);
				printf("Nascimento:%d/%d/%d\n", alunoCad[i].dia, alunoCad[i].mes, alunoCad[i].ano);
				if(alunoCad[i].al_inserido==1){
					printf("Matriculado: %s \n", alunoCad[i].disciplina);
					printf("codigo: %s \n", alunoCad[i].codigo);
					printf("Semestre: %d \n", alunoCad[i].semestre);
					printf("\n----------------\n");
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while (op!=0);
}


void listarProfessor(){
    int i,op;
	do{
		system("clear || cls");
		printf("_____LISTA DE PROFESSORES_____\n");
		for(i = 0; i < MAX; i++){
			if(professorCad[i].pf_ativo==1){
				printf("Nome: %s\n", professorCad[i].nome);
				printf("Matricula: %s\n", professorCad[i].matricula);
				printf("CPF: %s\n", professorCad[i].cpf);
				printf("Sexo: %s\n", professorCad[i].sexo);
				printf("Nascimento:%d/%d/%d\n", professorCad[i].dia, professorCad[i].mes, professorCad[i].ano);
				if(professorCad[i].pf_inserido==1){
					printf("Leciona: %s \n", professorCad[i].disciplina);
					printf("codigo: %s \n", professorCad[i].codigo);
					printf("Semestre: %d \n", professorCad[i].semestre);
				}
				printf("\n----------------\n");
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while (op!=0);
}


void listarDisciplina(){
    int i,op;

	do{
		system("clear || cls");
		printf("_____LISTA DE DISCIPLINAS_____\n");
		for(i=0;i<MAX;i++){
			if(disciplinaCad[i].disc_ativo==1){
				printf("Disciplina: %s\n", disciplinaCad[i].disciplina);
				printf("codigo: %s\n", disciplinaCad[i].codigo);
				printf("Semestre: %d\n", disciplinaCad[i].semestre);
				printf("\n----------------\n");
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while (op!=0);
}

void listarDadosDisciplina(){
	char codigo[14];
	int i, op;
	
	do{
		system("clear || cls");
		printf("Digite o codigo da disciplina para realizar pesquisa: ");
		fgets(codigo, sizeof(codigo), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(disciplinaCad[i].codigo, codigo)!=NULL){
				if(disciplinaCad[i].disc_ativo==1){
					printf("Disciplina: %s\n", disciplinaCad[i].disciplina);
					printf("codigo: %s\n", disciplinaCad[i].codigo);
					printf("Semestre: %d\n", disciplinaCad[i].semestre);
					printf("----------------\n");
					for(i=0;i<MAX;i++){
						if(strstr(alunoCad[i].disciplina, disciplinaCad[i].disciplina)!=NULL){
							if(alunoCad[i].al_ativo==1){
								printf("Alunos cadastrados na disciplina\n");
								printf("Nome: %s\n", alunoCad[i].nome);
								printf("Matricula: %s\n", alunoCad[i].matricula);
								printf("CPF: %s\n", alunoCad[i].cpf);
								printf("Sexo: %s\n", alunoCad[i].sexo);
								printf("Nascimento:%d/%d/%d\n", alunoCad[i].dia, alunoCad[i].mes, alunoCad[i].ano);
							}
						}
					}
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while (op!=0);
}

void listarAlunoSexo(){
    int i,op,sx;
	char sexo[10];

	
	do{
		system("clear || cls");
		printf("Escolha o sexo da busca");
		printf("\n1 - Masculino\n2 - Feminino\n3 - Outro\n");
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

		printf("_____LISTA DE ALUNOS_____\n");
		for(i=0;i<MAX;i++){
			if(alunoCad[i].al_ativo==1){
				if(strstr(alunoCad[i].sexo, sexo)!=NULL){
					printf("Nome: %s\n", alunoCad[i].nome);
					printf("Matricula: %s\n", alunoCad[i].matricula);
					printf("CPF: %s\n", alunoCad[i].cpf);
					printf("Sexo: %s\n", alunoCad[i].sexo);
					printf("Nascimento:%d/%d/%d\n", alunoCad[i].dia, alunoCad[i].mes, alunoCad[i].ano);
					if(alunoCad[i].al_inserido==1){
						printf("Matriculado: %s \n", alunoCad[i].disciplina);
						printf("codigo: %s \n", alunoCad[i].codigo);
						printf("Semestre: %d \n", alunoCad[i].semestre);
						printf("----------------\n");
					}
				}	
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while (op!=0);
}
void listarProfessorSexo(){
    int i,op,sx;
	char sexo[10];

	
	do{
		system("clear || cls");
		printf("Escolha o sexo da busca");
		printf("\n1 - Masculino\n2 - Feminino\n3 - Outro\n");
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

		printf("_____LISTA DE PROFESSORES_____\n");
		for(i=0;i<MAX;i++){
			if(professorCad[i].pf_ativo==1){
				if(strstr(professorCad[i].sexo, sexo)!=NULL){
					printf("Nome: %s\n", professorCad[i].nome);
					printf("Matricula: %s\n", professorCad[i].matricula);
					printf("CPF: %s\n", professorCad[i].cpf);
					printf("Sexo: %s\n", professorCad[i].sexo);
					printf("Nascimento:%d/%d/%d\n", professorCad[i].dia, professorCad[i].mes, professorCad[i].ano);
					if(professorCad[i].pf_inserido==1){
						printf("Matriculado: %s \n", professorCad[i].disciplina);
						printf("codigo: %s \n", professorCad[i].codigo);
						printf("Semestre: %d \n", professorCad[i].semestre);
						printf("----------------\n");
					}
				}	
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while (op!=0);
}
void listarAniversariantes(){
    int i,op;
	int dia, mes;

	
	do{
		system("clear || cls");
		printf("Digite o dia e mes de hoje");
		printf("\nDia :");
		scanf("%d", &dia);
		limparBuffer();
		printf("\nMes :");
		scanf("%d", &mes);
		limparBuffer();
		
		printf("\n_____LISTA DE ALUNOS ANIVERSARIANTES_____\n");
		for(i=0;i<MAX;i++){
			if(dia == alunoCad[i].dia){
				if(mes == alunoCad[i].mes){
					if(alunoCad[i].al_ativo == 1){
						printf("Nome: %s\n", alunoCad[i].nome);
						printf("Matricula: %s\n", alunoCad[i].matricula);
						printf("Sexo: %s\n", alunoCad[i].sexo);
						printf("Nascimento:%d/%d/%d\n", alunoCad[i].dia, alunoCad[i].mes, alunoCad[i].ano);
					}
				}
			}
		}
		printf("\n_____LISTA DE PROFESSORES ANIVERSARIANTES_____\n");
		for(i=0;i<MAX;i++){
			if(dia == professorCad[i].dia){
				if(mes == professorCad[i].mes){
					if(professorCad[i].pf_ativo == 1){
						printf("Nome: %s\n", professorCad[i].nome);
						printf("Matricula: %s\n", professorCad[i].matricula);
						printf("Sexo: %s\n", professorCad[i].sexo);
						printf("Nascimento:%d/%d/%d\n", professorCad[i].dia, professorCad[i].mes, professorCad[i].ano);
					}
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while (op!=0);
}

void listarAlunoNome(){
	char nome[20];
	int i, op;

	do{
		system("clear || cls");
		printf("\nDigite um nome para realizar pesquisa: ");
		fgets(nome, sizeof(nome), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(alunoCad[i].nome, nome)!=NULL){
				if(alunoCad[i].al_ativo==1){
					printf("Nome: %s\n", alunoCad[i].nome);
					printf("Matricula: %s\n", alunoCad[i].matricula);
					printf("CPF: %s\n", alunoCad[i].cpf);
					printf("Sexo: %s\n", alunoCad[i].sexo);
					printf("Nascimento:%d/%d/%d\n", alunoCad[i].dia, alunoCad[i].mes, alunoCad[i].ano);
					if(alunoCad[i].al_inserido==1){
						printf("\nMatriculado: %s \n", alunoCad[i].disciplina);
						printf("codigo: %s \n", alunoCad[i].codigo);
						printf("Semestre: %d \n", alunoCad[i].semestre);
						printf("\n----------------\n");
					}
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}
void listarProfessorNome(){
	char nome[20];
	int i, op;

	do{
		system("clear || cls");
		printf("\nDigite um nome para realizar pesquisa: ");
		fgets(nome, sizeof(nome), stdin);
		limparBuffer();
		for(i=0;i<MAX;i++){
			if(strstr(professorCad[i].nome, nome)!=NULL){
				if(professorCad[i].pf_ativo==1){
					printf("Nome: %s\n", professorCad[i].nome);
					printf("Matricula: %s\n", professorCad[i].matricula);
					printf("CPF: %s\n", professorCad[i].cpf);
					printf("Sexo: %s\n", professorCad[i].sexo);
					printf("Nascimento:%d/%d/%d\n", professorCad[i].dia, professorCad[i].mes, professorCad[i].ano);
					if(professorCad[i].pf_inserido==1){
						printf("\nMatriculado: %s \n", professorCad[i].disciplina);
						printf("codigo: %s \n", professorCad[i].codigo);
						printf("Semestre: %d \n", professorCad[i].semestre);
						printf("\n----------------\n");
					}
				}
			}
		}
		printf("\n0 - Sair\n");
		scanf("%d", &op);
		limparBuffer();
	}while(op!=0);
}