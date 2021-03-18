#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

//struct para cadastro do aluno
typedef struct{
	char nome[20], cpf[14], sexo[10], matricula[20];
	char disciplina[20],codigo[14]; 
    int dia,mes,ano,semestre;
	int al_ativo, al_inserido;
}Aluno;
Aluno alunos[MAX];

//struct para cadastro do professor
typedef struct{
	char nome[20], cpf[14], sexo[10], matricula[20], codigo[14], disciplina[20];
    int dia,mes,ano,semestre;
	int prof_ativo, prof_inserido;
}Professor;
Professor professores[MAX];

//struct para cadastro da disciplina
typedef struct{
	char disciplina[20],codigo[14];
    int semestre;
	int disc_ativo;
}Disciplina;
Disciplina disciplinas[MAX];


//declarações de blocos
//bloco de menu principal
void menu();

//bloco de menu de cadastro
void cadastrar();
//subblocos de cadastro
void cadastrarDisciplina();
void cadastrarAluno();
void cadastrarProfessor();

//bloco de menu de listagem
void listar();
//subblocos de listagem
void listarAluno();
void listarProfessor();
void listarDisciplina();

//bloco de inserir
void inserir();
//subblocos de insercao
void inserirAluno();
void inserirProfessor();

//bloco de menu pesquisa
void pesquisar();
//blocos de pesquisa
void pesquisarAluno();
void pesquisarDisciplina();
void pesquisarProfessor();

//bloco de exclusão
void remover();
//subblocos de remocao
void removerAluno();
void removerProfessor();
void removerDisciplina();
void removerDisciplinaAluno();
void removerDisciplinaProfessor();

//start
int main(){
	
	menu();
	
}

//menu principal
void menu(){
	int op;
	do{
		system("cls");
        printf("\n______Sistema Escolar_____\n\n");

		printf("\n1 - Cadastrar\n");
        printf("\n2 - Listar\n");
        printf("\n3 - Inserir\n");
        printf("\n4 - Remover\n");
        printf("\n5 - Pesquisar\n");
        //printf("\n5 - Pesquisar\n");
        printf("\n0 - Sair\n");
		scanf("%d", &op, stdin);
		getchar();

		switch(op){
			case 1:
				cadastrar();
			break;
			case 2: 
				listar();
			break;
			case 3:
				inserir();
			break;
			case 4:
				remover();
			break;
			case 5:
				pesquisar();
			break;
		}
		getchar();
	}while(op!=0);
}

//menu de cadastro
void cadastrar(){
    int op;
    do{
        system("cls");
        printf("\n1 - Cadastrar Aluno\n");
        printf("\n2 - Cadastrar Professor\n");
        printf("\n3 - Cadastrar Disciplina\n");
        printf("\n0 - Sair\n");
        scanf("%d", &op, stdin);
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

//cadastro do aluno
void cadastrarAluno(){
    char nome[20],cpf[14], sexo[10], matricula[20];
    int dia,mes,ano;
	int op,i;
    do{
		system("cls");
        fflush(stdin);
		printf("\nNome: ");
		fgets(nome, sizeof(nome), stdin);
		printf("\nMatricula: ");
		fgets(matricula, sizeof(matricula), stdin);
		printf("\nCPF: ");
		fgets(cpf, sizeof(cpf), stdin);
		printf("\nSexo: ");
		fgets(sexo, sizeof(sexo), stdin);
        printf("\nData de nascimento\n");
        printf("\nDia: ");
        scanf("%d", &dia, stdin);
        printf("\nMes: ");
        scanf("%d", &mes, stdin);
        printf("\nAno: ");
        scanf("%d", &ano, stdin);

		for(i = 0; i < MAX; i++){
			if(alunos[i].al_ativo == 0){
				strcpy(alunos[i].cpf, cpf);
				strcpy(alunos[i].matricula, matricula);
				strcpy(alunos[i].nome, nome);
				strcpy(alunos[i].sexo, sexo);
                alunos[i].dia=dia;
                alunos[i].mes=mes;
                alunos[i].ano=ano;
				alunos[i].al_ativo=1;
				break;
			}
		}
		printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &op, stdin);
	}while(op!=0);
}


//cadastro do professor
void cadastrarProfessor(){
    char nome[20],cpf[14], sexo[10], matricula[20];
    int dia,mes,ano;
	int op,i;
    do{
		system("cls");
        fflush(stdin);
		printf("\nNome: ");
		fgets(nome, sizeof(nome), stdin);
		printf("\nMatricula: ");
		fgets(matricula, sizeof(matricula), stdin);
		printf("\nCPF: ");
		fgets(cpf, sizeof(cpf), stdin);
		printf("\nSexo: ");
		fgets(sexo, sizeof(sexo), stdin);
        printf("\nData de nascimento\n");
        printf("\nDia: ");
        scanf("%d", &dia, stdin);
        printf("\nMes: ");
        scanf("%d", &mes, stdin);
        printf("\nAno: ");
        scanf("%d", &ano, stdin);

		for(i = 0; i < MAX; i++){
			if(professores[i].prof_ativo == 0){
				strcpy (professores[i].cpf, cpf);
				strcpy (professores[i].matricula, matricula);
				strcpy(professores[i].nome, nome);
				strcpy(professores[i].sexo, sexo);
                professores[i].dia=dia;
                professores[i].mes=mes;
                professores[i].ano=ano;
				professores[i].prof_ativo=1;
				break;
			}
		}
		printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &op, stdin);
	}while(op!=0);
}

//cadastro da disciplina
void cadastrarDisciplina(){
    char disciplina[20],codigo[14];
    int semestre;
    int op,i;
    do{
		system("cls");
        fflush(stdin);
        printf("\nDisciplina: ");
        fgets(disciplina, sizeof(disciplina), stdin);
        printf("\ncodigo: ");
        fgets(codigo, sizeof(codigo), stdin);
        printf("\nSemestre: ");
        scanf("%d", &semestre, stdin);
        for(i=0;i<MAX;i++){
			if(disciplinas[i].disc_ativo == 0){
				strcpy(disciplinas[i].disciplina, disciplina);
				strcpy(disciplinas[i].codigo, codigo);
                disciplinas[i].semestre=semestre;
				disciplinas[i].disc_ativo=1;
				break;
			}
		}
        printf("\n1 - Continuar cadastrando\n0 - Sair\n");
		scanf("%d", &op, stdin);
    }while(op!=0);
}

//menu de insercao
void inserir(){
	int op;
	do{
		system("cls");
		fflush(stdin);
		printf("\n1 - Inserir Aluno em disciplina\n");
		printf("\n2 - Inserir Professor em disciplina\n");
		printf("\n0 - Sair\n");
		scanf("%d", &op, stdin);
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
//inserir aluno em uma disciplina
void inserirAluno(){
	int op,i;
	char matricula[20], codigo[14];
	do{
		system("cls");
		fflush(stdin);
		printf("\nDigite a Matricula do aluno: \n");
		fgets(matricula, sizeof(matricula), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(alunos[i].matricula, matricula)!=NULL){
				printf("Pois bem %s\n", alunos[i].nome);
			}
		}
		printf("\nDigite o codigo da disciplina: \n");
		fgets(codigo, sizeof(codigo), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(alunos[i].matricula, matricula)!=NULL){
				if(strstr(disciplinas[i].codigo, codigo)!=NULL){
					if(alunos[i].al_inserido==0){
						strcpy(alunos[i].disciplina, disciplinas[i].disciplina);
						strcpy(alunos[i].codigo, disciplinas[i].codigo);
						alunos[i].semestre=disciplinas[i].semestre;
						alunos[i].al_inserido=1;
						printf("\nDisciplina Inserida\n");
						break;	
					}
				}
			}
		}
		printf("\n1 - Inserir outra\n0 - Sair\n");
		scanf("%d", &op, stdin);
	}while(op!=0);
}
//inserir professor numa disciplina
void inserirProfessor(){
	char matricula[20], codigo[14];
	int op,i;
	do{
		system("cls");
		fflush(stdin);
		printf("\nDigite a Matricula do professor: \n");
		fgets(matricula, sizeof(matricula), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(professores[i].matricula, matricula)!=NULL){
				printf("Pois bem %s\n", professores[i].nome);
			}
		}
		printf("\nDigite o codigo da disciplina: \n");
		fgets(codigo, sizeof(codigo), stdin);
		for(i=0;i<MAX;i++){
			if(strstr(professores[i].matricula, matricula)!=NULL){
				if(strstr(disciplinas[i].codigo, codigo)!=NULL){
					if(professores[i].prof_inserido==0){
						strcpy(professores[i].disciplina, disciplinas[i].disciplina);
						strcpy(professores[i].codigo, disciplinas[i].codigo);
						professores[i].semestre=disciplinas[i].semestre;
						professores[i].prof_inserido=1;
						printf("\nDisciplina Inserida\n");
						break;
					}
				}
			}
		}
		printf("\n1 - Inserir outra\n0 - Sair\n");
		scanf("%d", &op, stdin);
	}while(op!=0);
}



//menu de listagem
void listar(){
    int op;
    do{
		system("cls");
		fflush(stdin);
        printf("\n1 - Listar Alunos\n");
        printf("\n2 - Listar Professores\n");
        printf("\n3 - Listar Disciplinas\n");
        printf("\n0 - Sair\n");
        scanf("%d", &op);
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
        }
    }while(op!=0);
}

//listagem de alunos
void listarAluno(){
    int i,op;
	system("cls");
	fflush(stdin);
	printf("\n_____LISTA DE ALUNOS_____\n");
	for(i=0;i<MAX;i++){
		if(alunos[i].al_ativo==1){
			printf("Nome: %s\n", alunos[i].nome);
			printf("Matricula: %s\n", alunos[i].matricula);
			printf("CPF: %s\n", alunos[i].cpf);
			printf("Sexo: %s\n", alunos[i].sexo);
            printf("Nascimento:%d/%d/%d\n", alunos[i].dia, alunos[i].mes, alunos[i].ano);
			if(alunos[i].al_inserido==1){
				printf("\nMatriculado: %s \n", alunos[i].disciplina);
				printf("codigo: %s \n", alunos[i].codigo);
				printf("Semestre: %d \n", alunos[i].semestre);
				printf("\n----------------\n");
			}
		}
	}
    printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		listar();
	}
}

//listagem de professores
void listarProfessor(){
    int i,op;
	system("cls");
	fflush(stdin);
	printf("\n_____LISTA DE PROFESSORES_____\n");
	for(i = 0; i < MAX; i++){
		if(professores[i].prof_ativo==1){
			printf("Nome: %s\n", professores[i].nome);
			printf("Matricula: %s\n", professores[i].matricula);
			printf("CPF: %s\n", professores[i].cpf);
			printf("Sexo: %s\n", professores[i].sexo);
            printf("Nascimento:%d/%d/%d\n", professores[i].dia, professores[i].mes, professores[i].ano);
			if(professores[i].prof_inserido==1){
				printf("\nLeciona: %s \n", professores[i].disciplina);
				printf("codigo: %s \n", professores[i].codigo);
				printf("Semestre: %d \n", professores[i].semestre);
			}
			printf("\n----------------\n");
		}
	}
    printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		listar();
	}
}

//listagem de disciplinas
void listarDisciplina(){
    int i,op;
	system("cls");
	fflush(stdin);
	printf("\n_____LISTA DE DISCIPLINAS_____\n");
	for(i=0;i<MAX;i++){
		if(disciplinas[i].disc_ativo==1){
			printf("Disciplina: %s\n", disciplinas[i].disciplina);
			printf("codigo: %s\n", disciplinas[i].codigo);
            printf("Semestre: %d\n", disciplinas[i].semestre);
			printf("\n----------------\n");
		}
	}
    printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		listar();
	}
}

//menu de remocao
void remover(){
    int op;
    do{
		system("cls");
        printf("\n1 - Remover Aluno\n");
        printf("\n2 - Remover Professor\n");
        printf("\n3 - Remover Disciplina\n");
        printf("\n4 - Remover Disciplina do cadastro do aluno\n");
        printf("\n5 - Remover Disciplina do cadastro do professor\n");
        printf("\n0 - Sair\n");
        scanf("%d", &op);
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

//remover aluno do sistema
void removerAluno(){
	system("cls");
	char matricula[20];
	int i,op;
	fflush(stdin);
	printf("\nDigite a Matricula do aluno a ser removido: ");
	fgets(matricula, sizeof(matricula), stdin);
	for(i=0;i<MAX;i++){
		if(alunos[i].al_ativo==1){
			if(strstr(alunos[i].matricula, matricula)!=NULL){
				printf("Nome: %s\n", alunos[i].nome);
				printf("CPF: %s\n", alunos[i].cpf);
				printf("Matricula: %s\n", alunos[i].matricula);
				printf("\n----------------\n");	
				alunos[i].al_ativo=0;
				printf("Matricula removida com sucesso\n");
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		remover();
	}
}

//remover professor do sistema
void removerProfessor(){
	system("cls");
	char matricula[20];
	int i,op;
	fflush(stdin);
	printf("\nDigite a Matricula do professor a ser removido: ");
	fgets(matricula, sizeof(matricula), stdin);
	for(i=0;i<MAX;i++){
		if(professores[i].prof_ativo==1){
			if(strstr(professores[i].matricula, matricula)!=NULL){
				printf("Nome: %s\n", professores[i].nome);
				printf("CPF: %s\n", professores[i].cpf);
				printf("Matricula: %s\n", professores[i].matricula);
				printf("\n----------------\n");	
				professores[i].prof_ativo=0;
				printf("Matricula removida com sucesso\n");
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		remover();
	}
}

//remover disciplina do sistema
void removerDisciplina(){
	system("cls");
	char codigo[14];
	int i,op;
	fflush(stdin);
	printf("\nDigite o codigo da disciplina a ser removida: ");
	fgets(codigo, sizeof(codigo), stdin);
	for(i=0;i<MAX;i++){
		if(disciplinas[i].disc_ativo==1){
			if(strstr(disciplinas[i].codigo, codigo)!=NULL){
				printf("Disciplina: %s\n", disciplinas[i].disciplina);
				printf("codigo: %s\n", disciplinas[i].codigo);
				printf("Semestre: %d\n", disciplinas[i].semestre);
				printf("\n----------------\n");	
				disciplinas[i].disc_ativo=0;
				printf("Disciplina removida com sucesso\n");
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		remover();
	}
}

//remove alguma disciplina registrada em algum aluno
void removerDisciplinaAluno(){
	system("cls");
	char codigo[14],matricula[20];
	int i,op;
	fflush(stdin);
	printf("\nDigite a Matricula do aluno que terá uma disciplina removida: ");
	fgets(matricula, sizeof(matricula), stdin);
	for(i=0;i<MAX;i++){
		if(alunos[i].al_inserido==1){
			if(strstr(alunos[i].matricula, matricula)!=NULL){
				printf("Nome: %s\n", alunos[i].nome);
				printf("CPF: %s\n", alunos[i].cpf);
				printf("Matricula: %s\n", alunos[i].matricula);
				printf("Disciplina: %s\n", disciplinas[i].disciplina);
				printf("codigo: %s\n", disciplinas[i].codigo);
				printf("Semestre: %d\n", disciplinas[i].semestre);
				printf("\n----------------\n");	
				alunos[i].al_inserido=0;
				printf("Disciplina removida do cadastro do aluno com sucesso\n");
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		remover();
	}
}

//remove alguma disciplina registrada em algum professor
void removerDisciplinaProfessor(){
	system("cls");
	char codigo[14],matricula[20];
	int i,op;
	fflush(stdin);
	printf("\nDigite a Matricula do professor que terá uma disciplina removida: ");
	fgets(matricula, sizeof(matricula), stdin);
	for(i=0;i<MAX;i++){
		if(professores[i].prof_inserido==1){
			if(strstr(professores[i].matricula, matricula)!=NULL){
				printf("Nome: %s\n", professores[i].nome);
				printf("CPF: %s\n", professores[i].cpf);
				printf("Matricula: %s\n", professores[i].matricula);
				printf("Disciplina: %s\n", disciplinas[i].disciplina);
				printf("codigo: %s\n", disciplinas[i].codigo);
				printf("Semestre: %d\n", disciplinas[i].semestre);
				printf("\n----------------\n");	
				professores[i].prof_inserido=0;
				printf("Disciplina removida do cadastro do professor com sucesso\n");
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		remover();
	}
}

//menu para realização de pesquisa individual
void pesquisar(){
	int op;
    do{
		system("cls");
        printf("\n1 - Pesquisar Aluno\n");
        printf("\n2 - Pesquisar Professor\n");
        printf("\n3 - Pesquisar Disciplina\n");
        printf("\n0 - Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                pesquisarAluno();
            break;
            case 2:
                pesquisarProfessor();
            break;
            case 3:
                pesquisarDisciplina();
            break;
        }
    }while(op!=0);
}

void pesquisarAluno(){
	char matricula[20];
	int i, op;
	system("cls");
	fflush(stdin);
	printf("\nDigite a matricula do aluno para realizar pesquisa: ");
	fgets(matricula, sizeof(matricula), stdin);
	for(i=0;i<MAX;i++){
		if(strstr(alunos[i].matricula, matricula)!=NULL){
			if(alunos[i].al_ativo==1){
				printf("Nome: %s\n", alunos[i].nome);
				printf("Matricula: %s\n", alunos[i].matricula);
				printf("CPF: %s\n", alunos[i].cpf);
				printf("Sexo: %s\n", alunos[i].sexo);
				printf("Nascimento:%d/%d/%d\n", alunos[i].dia, alunos[i].mes, alunos[i].ano);
				if(alunos[i].al_inserido==1){
					printf("\nMatriculado: %s \n", alunos[i].disciplina);
					printf("codigo: %s \n", alunos[i].codigo);
					printf("Semestre: %d \n", alunos[i].semestre);
					printf("\n----------------\n");
				}
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		pesquisar();
	}
}

void pesquisarProfessor(){
	char matricula[20];
	int i, op;
	system("cls");
	fflush(stdin);
	printf("\nDigite a matricula do professor para realizar pesquisa: ");
	fgets(matricula, sizeof(matricula), stdin);
	for(i=0;i<MAX;i++){
		if(strstr(professores[i].matricula, matricula)!=NULL){
			if(professores[i].prof_ativo==1){
				printf("Nome: %s\n", professores[i].nome);
				printf("Matricula: %s\n", professores[i].matricula);
				printf("CPF: %s\n", professores[i].cpf);
				printf("Sexo: %s\n", professores[i].sexo);
				printf("Nascimento:%d/%d/%d\n", professores[i].dia, professores[i].mes, professores[i].ano);
				if(professores[i].prof_inserido==1){
					printf("\nLeciona: %s \n", professores[i].disciplina);
					printf("codigo: %s \n", professores[i].codigo);
					printf("Semestre: %d \n", professores[i].semestre);
				}
				printf("\n----------------\n");
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		pesquisar();
	}
}

void pesquisarDisciplina(){
	char codigo[14];
	int i, op;
	system("cls");
	fflush(stdin);
	printf("\nDigite o codigo da disciplina para realizar pesquisa: ");
	fgets(codigo, sizeof(codigo), stdin);
	for(i=0;i<MAX;i++){
		if(strstr(disciplinas[i].codigo, codigo)!=NULL){
			if(disciplinas[i].disc_ativo==1){
				printf("Disciplina: %s\n", disciplinas[i].disciplina);
				printf("codigo: %s\n", disciplinas[i].codigo);
				printf("Semestre: %d\n", disciplinas[i].semestre);
				printf("\n----------------\n");
			}
		}
	}
	printf("\n0 - Sair\n");
	scanf("%d", &op, stdin);
    if(op==0){
		pesquisar();
	}
}