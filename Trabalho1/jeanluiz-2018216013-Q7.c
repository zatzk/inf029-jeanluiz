#include <stdio.h>
#include <stdlib.h>
#define VAZIO 32

void players();
void game();
int checagem();
void limpaBuffer();

struct Dados{
	char tab[3][3];
    char playerA[10], playerB[10];
};

struct Dados hash;

int main(){
   	players();
}
void players(){
	printf("Cadastre os jogadores\n");
    printf("Jogador 1: \n");
    fgets(hash.playerA, sizeof hash.playerA, stdin);

    printf("Jogador 2: \n");
    fgets(hash.playerB, sizeof hash.playerB, stdin);

	game();
}
void game(){
	 int i, j, flag=0, change=0,posX, posY, contX=0, contO=0;

	printf("___Jogo da velha___\n\n");
    for(i=0; i<3; i++){
        for(j=0;j<3;j++){
            hash.tab[i][j] = VAZIO;
        }
    }
    do{ 
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                printf("|%c|", hash.tab[i][j]);
            }
        printf("\n");  
        for(j = 0; j < 3; j++){
            printf("___"); 
        }
        printf("\n");  
        }
        if(change==0){
            printf("Vez do %s\n", hash.playerA);
            printf("Informe a posicao a ser jogada em matriz:\n");
            scanf("%d %d", &posX, &posY);
            if(hash.tab[posX][posY] == VAZIO){
                hash.tab[posX][posY] = 'X';
                contX++;
                change=1;
            }
            system("cls||clear");
        }
         else if(change==1){
            printf("Vez do %s\n", hash.playerB);
            printf("Informe a posicao a ser jogada em matriz:\n");
            scanf("%d %d", &posX, &posY);
			limpaBuffer();
            if(hash.tab[posX][posY] == VAZIO){
                hash.tab[posX][posY] = 'O';
                contO++;
                change=0;
            }
            system("cls||clear");
        }

		if((contX>=3) || (contO>=3)){
		flag = checagem();
		}
	}while(flag!=1);
}

int checagem(){
		if(hash.tab[0][0]=='X'&& hash.tab[0][1]=='X' && hash.tab[0][2]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[1][0]=='X'&& hash.tab[1][1]=='X' && hash.tab[1][2]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[2][0]=='X'&& hash.tab[2][1]=='X' && hash.tab[2][2]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][0]=='X'&& hash.tab[1][1]=='X' && hash.tab[2][2]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][2]=='X'&& hash.tab[1][1]=='X' && hash.tab[2][0]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][0]=='X'&& hash.tab[1][0]=='X' && hash.tab[2][0]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][1]=='X'&& hash.tab[1][1]=='X' && hash.tab[2][1]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][2]=='X'&& hash.tab[1][2]=='X' && hash.tab[2][2]=='X'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }

        

        else if(hash.tab[0][0]=='O'&& hash.tab[0][1]=='O' && hash.tab[0][2]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[1][0]=='O'&& hash.tab[1][1]=='O' && hash.tab[1][2]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[2][0]=='O'&& hash.tab[2][1]=='O' && hash.tab[2][2]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][0]=='O'&& hash.tab[1][1]=='O' && hash.tab[2][2]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][2]=='O'&& hash.tab[1][1]=='O' && hash.tab[2][0]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][0]=='O'&& hash.tab[1][0]=='O' && hash.tab[2][0]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][1]=='O'&& hash.tab[1][1]=='O' && hash.tab[2][1]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
        else if(hash.tab[0][2]=='O'&& hash.tab[1][2]=='O' && hash.tab[2][2]=='0'){
            printf("Jogador %s venceu!", hash.playerA);
            return 1;
        }
}

void limpaBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}