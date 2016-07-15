#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pilhaPALAVRAS.h"
#include "stackCLASS.h"

#define CLASS_LINE '+'
#define WORD_LINE '-'
#define TIPS_DELIMITER ','

void readFile_setClasses(CLASS_MY *Class);

void showAll(CLASS_MY *Class);

int main()
{
	CLASS_MY *class_head = (CLASS_MY *) malloc(sizeof(CLASS_MY));//Alocando a cabeca da pilha de categorias
	class_head->word_head = (WORD_MY *) malloc(sizeof(WORD_MY));//alocando a cabeca da pilha de palavras

	start_stackClass(class_head);//Iniciando a pilha de categorias e sua respectiva pilha de palavras

	readFile_setClasses(class_head);

	showAll(class_head);

	system("PAUSE");
	return 0;
}


void readFile_setClasses(CLASS_MY *Class)
{
	char URL[] = "bancoDados.txt";
	FILE *arq;
	
	char CODE_LINE,//going to tell what to read( a class name, a word name and its tips)
		 trashBuff;//characters like '\n' and ',' that the READ can discards

	arq = fopen(URL, "r");
	if(arq == NULL)
	{
		printf("[ERROR]: file \"%s\" cannot be open.\n", URL);
		system("pause");
		exit(1);
	}
	
	while((CODE_LINE = fgetc(arq)) != EOF)
	{
		if(CODE_LINE == CLASS_LINE)
		{
			char Class_name[30];

			fscanf(arq, "%[^\n]s", Class_name);
			trashBuff = fgetc(arq);
			
			pushClass(Class, Class_name);
		}
		else if(CODE_LINE == WORD_LINE)	
		{
			char Word_name[30], tip1[20], tip2[20], tip3[20];
		    fscanf(arq, "%[^,]s", Word_name);
			trashBuff = fgetc(arq);

			fscanf(arq, "%[^,]s", tip1);
			trashBuff = fgetc(arq);

			fscanf(arq, "%[^,]s", tip2);
			trashBuff = fgetc(arq);

			fscanf(arq, "%[^\n]s", tip3);
			trashBuff = fgetc(arq);
		
			pushWord_in_stackClass(Class, Word_name, tip1, tip2, tip3);
		}
	}
}

//terminar a funcao de exibir as categorias e palavras
void showAll(CLASS_MY *Class)
{
	CLASS_MY *aux = Class->upClass;
	if(aux != NULL)
	{
		do
		{
			printf("\n\nCategoria: %s\n", aux->className);
			showWords(aux->word_head);
			aux = aux->upClass;
		}while(aux != NULL);
	}else
		printf("Nao existe palavra salva");
}
