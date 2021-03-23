// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Jean Luiz de Souza Junior
//  email: juniorjean7@gmail.com
//  Matrícula: 2018216013
//  Semestre: 3ª

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char *data){
    int datadia, datames, dataano;
    if(sscanf(data, "%d/%d/%d", &datadia, &datames, &dataano)==3){
        if((datadia >=1 && datadia <=31) && (datames >= 1 && datames <=12)){
            if((datames==1)||(datames==3)||(datames==5)||(datames==7)||(datames==8)||(datames==10)||(datames==12) && (datadia <=31)){
                return 1;
            }
            if((datames==2) && (datadia <=28)){
                return 1;
            }
            if((datames==2) && (datadia ==29)){
                if(dataano%4==0 && (dataano%100!=0 || dataano%400==0)){
                    return 1;
                }
            }
            if((datames==4)||(datames==6)||(datames==9)||(datames==11) && (datadia <=30)){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    //calcule os dados e armazene nas três variáveis a seguir
    int data1, data2, nDias = 0, nMeses = 0, nAnos = 0, mes1, dia1, ano1, mes2, dia2, ano2, cont= 0, quant = 0, aux = 0, i=0;
    int Ndias1 = 0;

    if (q1(datainicial) == 0)
        return 2;

    if (q1(datafinal) == 0)
        return 3;

    if(datainicial[0] >=0 && datainicial[1] != '/'){
        dia1 = (datainicial[0] - '0') * 10;
        dia1 = dia1 + (datainicial[1] - '0');
        cont = 3;
      }else if(datainicial[0] >= 0 && datainicial[1] == '/'){
        dia1 = datainicial[0] - '0';
        cont = 2;
      }

      if(datainicial[cont] >= 0 && datainicial[cont + 1] != '/'){
        mes1 = (datainicial[cont] - '0') * 10;
        mes1 = mes1 + (datainicial[cont + 1] - '0');
        cont = cont + 2;
      }else if (datainicial[cont] >= 0 && datainicial[cont + 1] == '/'){
        mes1 = datainicial[cont] - '0';
        cont = cont + 1;
      }

      for(i=cont; datainicial[i] != '\0'; i++){
        aux++;
        if(aux == 3){
          ano1 = 2000;
          ano1 = ano1 + (datainicial[i - 1]-'0') * 10;
          ano1 = ano1 + (datainicial[i]-'0');
        }else if(aux == 5){
            ano1 = (datainicial[i - 3] - '0') * 1000;
            ano1 = ano1 + (datainicial[i - 2] - '0') * 100;
            ano1 = ano1 + (datainicial[i - 1] - '0') * 10;
            ano1 = ano1 + (datainicial[i] - '0');
        }
      }

    cont = 0; quant = 0; aux = 0; i=0;

    if(datafinal[0] >=0 && datafinal[1] != '/'){
        dia2 = (datafinal[0] - '0') * 10;
        dia2 = dia2 + (datafinal[1] - '0');
        cont = 3;
      }else if(datafinal[0] >= 0 && datafinal[1] == '/'){
        dia2 = datafinal[0] - '0';
        cont = 2;
      }

      if(datafinal[cont] >= 0 && datafinal[cont + 1] != '/'){
        mes2 = (datafinal[cont] - '0') * 10;
        mes2 = mes2 + (datafinal[cont + 1] - '0');
        cont = cont + 2;
      }else if (datafinal[cont] >= 0 && datafinal[cont + 1] == '/'){
        mes2 = datafinal[cont] - '0';
        cont = cont + 1;
      }

      for(i=cont; datafinal[i] != '\0'; i++){
        aux++;
        if(aux == 3){
          ano2 = 2000;
          ano2 = ano2 + (datafinal[i - 1]-'0') * 10;
          ano2 = ano2 + (datafinal[i]-'0');
        }else if(aux == 5){
            ano2 = (datafinal[i - 3] - '0') * 1000;
            ano2 = ano2 + (datafinal[i - 2] - '0') * 100;
            ano2 = ano2 + (datafinal[i - 1] - '0') * 10;
            ano2 = ano2 + (datafinal[i] - '0');
        }
      }

    data1 = (ano1 * 10000) + (mes1 * 100) + dia1;
    data2 = (ano2 * 10000) + (mes2 * 100) + dia2;

    if(data1 > data2){
      return 4;
    }

    for(i = mes1+1; i != mes2 || ano1 != ano2; i++){
  		nMeses++;
  		if(i==12){
  			i=0;
  			ano1++;
  		}
  		if(i==mes2 && ano1==ano2)
  			break;
    }

  	if((mes1 == 4 || mes1 == 6 || mes1 == 9 || mes1 == 11)){
  		Ndias1 = 30 - dia1;
  		nDias = Ndias1 + dia2;
  		while(nDias>=30){
  			nMeses++;
  			nDias-=30;}
  	}

  	if((mes1 == 1 || mes1 == 3 || mes1 == 5 || mes1 == 7 || mes1 ==8 || mes1 == 10 || mes1 == 12)){
  		Ndias1 = 31 - dia1;
  		nDias = Ndias1 + dia2;
  		while(nDias>=31){
  			nMeses++;
  			nDias-=31;}
  	}

  	if(mes1 == 2){
  		Ndias1 = 28 - dia1;
  		nDias = Ndias1 + dia2;
  		while(nDias>=28){
  			nMeses++;
  			nDias-=28;}
  	}

  	if(mes1 == 2 && (ano1 % 4) == 0){
  		Ndias1 = 29 - dia1;
  		nDias = Ndias1 + dia2;
  		while(nDias>=29){
  			nMeses++;
  			nDias-=29;}
  	}

  	while(nMeses>=12){
  		nAnos++;
  		nMeses-=12;
  	}
    /*mantenha o código abaixo, para salvar os dados em
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;
    //coloque o retorno correto
    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;
    int i;
    char string[250];

    strcpy (string, texto);

    if(isCaseSensitive == 1){
      for(i=0; string[i] != '\0'; i++){
        if(string[i] == c){
          qtdOcorrencias++;
        }
      }
    }
    else if(isCaseSensitive == 0){
      for(i = 0; string[i] != '0'; i++){

        if(string[i] == c)
          qtdOcorrencias++;

        if(string[i] == c - 32)
          qtdOcorrencias++;

        if(string[i] == c + 32)
          qtdOcorrencias++;
        }
      }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int i,j,qtdOcorrencias=0,x=0,aux_i=0, k = 0, cont = 0;

  	for (i=0;i<strlen(strTexto);i++){
  		if (strBusca[0]==strTexto[i]){
        posicoes[k] = i+1;
  			aux_i=i;
  			x=0;
  			for(j=0;j<strlen(strBusca);j++)
  			{
  				if(strBusca[j]==strTexto[aux_i])
  				{
  					x++;
  				}
  				aux_i++;
  			}
  			if (x>=strlen(strBusca)){
  				qtdOcorrencias++;
                  k++;
                  posicoes[k] = i + x;
                  k++;

              }
              else
                  posicoes[k] = -1;
  		}
  	}
  	if (qtdOcorrencias>=1)
          for (i = 0; posicoes[i] != -1; i++)


    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    int inv;

    inv = 0;
    while (num > 0) {
        inv = 10 * inv + num % 10;
        num /= 10;
    }
    num=inv;

    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias = 0;
    char snum[20], sbusca[20];
    int i, j, x, aux = 0;
    sprintf(snum, "%i", numerobase);
    sprintf(sbusca, "%i",numerobusca);

    for (i=0;i<strlen(snum);i++){
      if (sbusca[0]==snum[i]){
        aux=i;
        x=0;
        for(j=0;j<strlen(sbusca);j++){
          if(sbusca[j]==snum[aux]){
            x++;
          }
          aux++;
        }
        if (x>=strlen(sbusca)){
          qtdOcorrencias++;
        }
      }
    }
      return qtdOcorrencias;
}