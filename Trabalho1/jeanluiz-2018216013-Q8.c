#include <stdio.h>
#include <stdlib.h>
#define VAZIO 32

void players();
void game();
void limpaBuffer();

struct Dados{
	char tab[5][5];
    char playerA[10], playerB[10];
};

struct Dados naval;

int main(){
   	players();
}
void players(){
	printf("Cadastre os jogadores\n");
    printf("Jogador 1: \n");
    fgets(naval.playerA, sizeof naval.playerA, stdin);
    limpaBuffer();
    printf("Jogador 2: \n");
    fgets(naval.playerB, sizeof naval.playerB, stdin);
    limpaBuffer();
	game();
}

void game(){
    int i, j, flag=0, change=0,posX, posY, contX=0, contO=0;
    int navio[5][5];

    printf("___Batalha Naval___\n\n");
    for(i=0; i<5; i++){
        for(j=0;j<5;j++){
            naval.tab[i][j] = VAZIO;
        }
    }
    for(i=0; i<5; i++){
        for(j=0;j<5;j++){
            navio[i][j] = VAZIO;
        }
    }

    navio[1][2] =1;
    navio[2][2] =1;
    navio[0][2] =1;
    navio[5][5] =1;
    navio[3][3] =1;
    navio[4][1] =1;
    navio[0][4] =1;

    do{
        system("cls||clear");
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                printf("|%c|", naval.tab[i][j]);
            }
        printf("\n");  
        for(j = 0; j < 5; j++){
            }
        printf("\n");  
        }

        if(change==0){
            printf("Vez do %s\n", naval.playerA);
            printf("Informe a posicao a ser jogada em matriz:\n");
            scanf("%d %d", &posX, &posY);
            limpaBuffer();
            if((naval.tab[posX][posY] == VAZIO) && (navio[posX][posY] == 1)){
                naval.tab[posX][posY] = 'X';
                contX++;
            }
            else if((naval.tab[posX][posY] == VAZIO) && (navio[posX][posY] != 1)){
                naval.tab[posX][posY] = '*';
            }
            change=1;
        }

        else if(change==1){
            printf("Vez do %s\n", naval.playerB);
            printf("Informe a posicao a ser jogada em matriz:\n");
            scanf("%d %d", &posX, &posY);
            limpaBuffer();
            if((naval.tab[posX][posY] == VAZIO) && (navio[posX][posY] == 1)){
                naval.tab[posX][posY] = 'X';
                contO++;
            }
            else if((naval.tab[posX][posY] == VAZIO) && (navio[posX][posY] != 1)){
                naval.tab[posX][posY] = '*';
            } 
            change=0;
        }
        system("cls||clear");

        if(contX==3){
            printf("Jogador %s venceu!", naval.playerA);
            flag=1;
        }
        else if(contO==3){
            printf("Jogador %s venceu!", naval.playerB);
            flag=1;
        }
    }while(flag!=1);
}
void limpaBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}