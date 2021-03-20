#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "limparbuffer.h"



void limparBuffer(void){

	char c;
	while((c = getchar()) != '\n' && c != EOF);

}