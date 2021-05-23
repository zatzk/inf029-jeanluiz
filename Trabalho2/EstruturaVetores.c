#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

void dobrar(int *x)
{

    *x = *x * 2;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }

    else if(tamanho < 1)
        retorno = TAMANHO_INVALIDO;

    else{
        if(existeEstrAux(posicao) != SEM_ESTRUTURA_AUXILIAR){
             retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        }
           
        else{
            retorno = SUCESSO;
        }
            
    }

    if(retorno == SUCESSO){

        // Faz a alocação da Estrutura Auxiliar
        vetorPrincipal[posicao - 1].pvetAux = malloc(tamanho * sizeof(int));
        vetorPrincipal[posicao - 1].tamvetAux = tamanho;
        
        // Verifica se existe espaço
        if(temEspacoMemoria(posicao) != SUCESSO){
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
            
    } 

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
    int retorno = 0;

    if (ehPosicaoValida(posicao)!=SUCESSO){
        retorno = POSICAO_INVALIDA;
    }
        
    else{
        if(existeEstrAux(posicao)){
            if(temEspacoEstrAux(posicao)==SUCESSO){
                vetorPrincipal[posicao - 1].pvetAux[vetorPrincipal[posicao - 1].qtdElem] = valor;
          		vetorPrincipal[posicao - 1].qtdElem += 1;
                retorno = SUCESSO;
            }
            else{
                retorno = SEM_ESPACO;
            }
        }

        else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }

    else {
    	if(existeEstrAux(posicao) != JA_TEM_ESTRUTURA_AUXILIAR){
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    		
    	else{
    		if(estrAuxVazia(posicao) != SUCESSO)
    			retorno = ESTRUTURA_AUXILIAR_VAZIA;
    		else {
    			vetorPrincipal[posicao - 1].pvetAux[vetorPrincipal[posicao - 1].qtdElem - 1] = 0;
    			vetorPrincipal[posicao - 1].qtdElem -= 1;
    			retorno = SUCESSO;
    		}
    	}
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    int retorno = 0;
    int cont = 0, posAux = 0;
    int i, j;
    	
    if(ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }

    else{
    	if(existeEstrAux(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
    		retorno = SEM_ESTRUTURA_AUXILIAR;
    	else{
    		if(estrAuxVazia(posicao) != SUCESSO){
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
    			
    		else{
    			for(i = 0; i < vetorPrincipal[posicao - 1].qtdElem; i++){
                    if(valor != vetorPrincipal[posicao - 1].pvetAux[i]){
                        cont++;
                        if(cont == vetorPrincipal[posicao - 1].qtdElem){
                            retorno = NUMERO_INEXISTENTE;
                            break;
                        }
                    }
                    else{
    				    vetorPrincipal[posicao - 1].pvetAux[i] = 0;
    					posAux = i;
    					for(j = posAux; j < vetorPrincipal[posicao - 1].qtdElem - 1; j++){
    						vetorPrincipal[posicao - 1].pvetAux[j] = vetorPrincipal[posicao - 1].pvetAux[j + 1];
    					}
    					vetorPrincipal[posicao - 1].qtdElem--;
    					retorno = SUCESSO;
    				}
    			}
    		}
    	}
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;
    int i;

    if(ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }

    else{
    	if(existeEstrAux(posicao) != JA_TEM_ESTRUTURA_AUXILIAR){
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    		
    	else{
    		for(i = 0; i < vetorPrincipal[posicao - 1].qtdElem; i++){
    			vetorAux[i] = vetorPrincipal[posicao - 1].pvetAux[i];
    		}
    		retorno = SUCESSO;
    	}
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;
    int aux = 0;
    int i, j;

    if(ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }
    	
    else{
    	if(existeEstrAux(posicao) != JA_TEM_ESTRUTURA_AUXILIAR)
    		retorno = SEM_ESTRUTURA_AUXILIAR;
    	else{
    		for(i = 0; i < vetorPrincipal[posicao - 1].qtdElem; i++){
    			for(j = i + 1; j < vetorPrincipal[posicao - 1].qtdElem; j++){
    				if(vetorAux[i] > vetorAux[j]){
    					aux = vetorAux[i];
    					vetorAux[i] = vetorAux[j];
    					vetorAux[j] = aux;
    				}
    			}
    		}
    		retorno = SUCESSO;
    	}
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0;
    int cont = 0, vazio = 0;
    int i, j;

    for(i = 0; i < TAM; i++){
    	if(vetorPrincipal[i].qtdElem > 0){
    		vazio++;
    		for(j = 0; j < vetorPrincipal[i].qtdElem; j++){
    			vetorAux[cont] = vetorPrincipal[i].pvetAux[j]; 
    			cont++;
    		}
    	}
    }

    if(vazio == 0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    	
    else{
        retorno = SUCESSO;
    }
    	
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0;
    int cont = 0, vazio = 0;
    int i, j, aux;


    for(i = 0; i < TAM; i++){
    	if(vetorPrincipal[i].qtdElem > 0){
    		vazio++;
    		for(j = 0; j < vetorPrincipal[i].qtdElem; j++){
    			vetorAux[cont] = vetorPrincipal[i].pvetAux[j]; 
    			cont++;
    		}
    	}
    }

    for(i = 0; i < cont; i++){
    	for(j = i + 1; j < cont; j++){
    		if(vetorAux[i] > vetorAux[j]){
    			aux = vetorAux[i];
    			vetorAux[i] = vetorAux[j];
    			vetorAux[j] = aux;
    		}
    	}
    }

    if(vazio == 0){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else{
        retorno = SUCESSO;
    }
    	
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }
    

    else if((vetorPrincipal[posicao - 1].tamvetAux + novoTamanho) < 1){
        retorno = NOVO_TAMANHO_INVALIDO;
    }

    else{
    	if(existeEstrAux(posicao) != JA_TEM_ESTRUTURA_AUXILIAR){
    		retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    	else{
    		retorno = SUCESSO;
        }
    }

    if(retorno == SUCESSO){
    	
    	vetorPrincipal[posicao - 1].pvetAux = realloc(vetorPrincipal[posicao - 1].pvetAux, (vetorPrincipal[posicao - 1].tamvetAux + novoTamanho));
    	vetorPrincipal[posicao - 1].tamvetAux += novoTamanho;

    	if(novoTamanho < 0){
            vetorPrincipal[posicao - 1].qtdElem += novoTamanho;
        }

    	if(temEspacoMemoria(posicao) != SUCESSO){
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
    }
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int retorno = 0;
    
    if(ehPosicaoValida(posicao) != SUCESSO){
        retorno = POSICAO_INVALIDA;
    }
    else {
    	if(existeEstrAux(posicao) != JA_TEM_ESTRUTURA_AUXILIAR){
    		retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    	else{
    		if(estrAuxVazia(posicao) != SUCESSO){
    			retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
    		else{
    			retorno = vetorPrincipal[posicao - 1].qtdElem;
            }
    	}
    }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar(){
    int i = 0;
    while(i<TAM){
        vetorPrincipal[i].pvetAux = NULL;
        vetorPrincipal[i].tamvetAux = 0;
        vetorPrincipal[i].qtdElem = 0;
        i++;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/


void finalizar(){
    int i = 0;
    while(i<TAM){
		if(existeEstrAux(i) == JA_TEM_ESTRUTURA_AUXILIAR){
			free(vetorPrincipal[i].pvetAux);
			vetorPrincipal[i].tamvetAux = 0;
			vetorPrincipal[i].qtdElem = 0;
            i++;
		}
	}
}

// se existe estrutura auxiliar
int existeEstrAux(int posicao){
    int retorno = 0;
    if(vetorPrincipal[posicao - 1].pvetAux!=NULL)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    else
        retorno = SEM_ESTRUTURA_AUXILIAR;

    return retorno;
}

int temEspacoEstrAux(int posicao){
	int retorno = 0;
	if(vetorPrincipal[posicao - 1].qtdElem >= vetorPrincipal[posicao - 1].tamvetAux)
		retorno = SEM_ESPACO;
	else
		retorno = SUCESSO;

	return retorno;
}

int temEspacoMemoria(int posicao){
    int retorno = 0;
    if(vetorPrincipal[posicao - 1].pvetAux == NULL)
        retorno = SEM_ESPACO_DE_MEMORIA;
    else
        retorno = SUCESSO;

    return retorno;
}
int estrAuxVazia(int posicao){
	int retorno = 0;
	if(vetorPrincipal[posicao - 1].qtdElem == 0)
		retorno = ESTRUTURA_AUXILIAR_VAZIA;
	else
		retorno = SUCESSO;

	return retorno;
}