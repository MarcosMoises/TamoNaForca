#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordHelper.h"
#include "PILHAS.h"

WORD_MY_AUX *create_Word(char *name, char *tips1, char *tips2, char *tips3)
{
	WORD_MY_AUX *word = (WORD_MY_AUX *) malloc(sizeof(WORD_MY_AUX));

	word->name = strdup(name);
	word->tips[0] = strdup(tips1);
	word->tips[1] = strdup(tips2);
	word->tips[2] = strdup(tips3);

	return word;
}

//checa a primeira ocorrencia de ch no struct->nome
char *check_Char_Word(WORD_MY_AUX *word, char CH)
{
	char *posCH = 0;
	
	posCH = strchr(word->name, CH);

	return posCH;
}

//verifica o tamanho de "name" em word (word->name)
int word_Length(WORD_MY_AUX *word)
{
	unsigned int wordLength = strlen(word->name);
	if(wordLength >= 1 && wordLength <= 6)
		return SMALL_WORD;
	else if(wordLength > 6 && wordLength <= 13)
		return MEDIUM_WORD;
	else
		return LONG_WORD;
}


void start_Name_Aux(WORD_MY_AUX *random, char *randomNameAux[2])
{
	randomNameAux[0] = strdup(random->name);
	randomNameAux[1] = strdup(random->name);

	char *ptr = randomNameAux[1];
	while(*ptr != '\0')
	{
		*ptr = '0'; 
		ptr++;
	}
}

void show_Name_Aux(char *wordAux[])
{
	char *ptr[2];
	ptr[0] = wordAux[0];
	ptr[1] = wordAux[1];

	while(*ptr[0] != '\0')
	{
		if(*ptr[1] == '1')
			printf("%c ", *ptr[0]);
		else
			printf("_ ");
		ptr[1]++;
		ptr[0]++;
	}
}

//exibir as dicas de acordo com a proporcao dos erros
void show_Tips(WORD_MY_AUX *random, int errorsTotal, int errorsMax)
{
	int metade = errorsMax/2;

	if(errorsTotal < metade){
		printf("dica 1: %s", random->tips[0]);
	}else if(errorsTotal == metade){
		printf("dica 1: %s\n", random->tips[0]);
		printf("dica 2: %s", random->tips[1]);
	}else{
		printf("dica 1: %s\n", random->tips[0]);
		printf("dica 2: %s\n", random->tips[1]);
		printf("dica 3: %s", random->tips[2]);	
	}
}

//procura pelo char Input na PILHA Inputs
int chk_Input_Inputs(NODE *Inputs, char Input)
{
	//verificar nos caracteres informados
	if(search_int(Inputs, Input))
		return 1;//encontrou
	else
		return 0;	
}

//procura por CH valido na palavra
//valido: com o segundo ponteiro em 0 para a mesma posicao
//nao achou: retorna 0
//achou um valido: retorna 1
//achou um invalido: retorna 2
int chk_Input_nameAux(char Input, char* nameAux[])
{
	char *ptr[2];
	ptr[0] = nameAux[0];
	ptr[1] = nameAux[1];

	while(*ptr[0] != '\0')
	{
		//achou o caractere
		if(*ptr[0] == Input)
		{
			if(*ptr[1] == '0')
				return 1;//eh valido
			else
				return 2;//eh invalido
		}
		ptr[0]++;
		ptr[1]++;
	}

	//nao achou o Inputs no nameAux
	return 0;
}

void delete_CH_nameAux(char CH, char *nameAux[])
{
	char *ptr[2];
	ptr[0] = nameAux[0];
	ptr[1] = nameAux[1];

	while(*ptr[0] != '\0')
	{
		if(*ptr[0] == CH && *ptr[1] == '0')
			*ptr[1] = '1';
		ptr[0]++;
		ptr[1]++;
	}	
}

//checa se todo toda a palavra esta invalidada
//com todos seus correspondentes sendo '1'
//EC.: L O V E
//     1 1 1 1
//return 1 -> a palavra esta totalmente invalidada
int chk_allInvalid_nameAux(char *nameAux[])
{
	char *ptr1 = nameAux[1];

	while(*ptr1 != '\0')
	{
		if(*ptr1 == '0')
			return 0;
		ptr1++;
	}	

	return 1;
}
