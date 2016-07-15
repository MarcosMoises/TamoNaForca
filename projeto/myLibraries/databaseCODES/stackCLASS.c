#include <stdio.h>
#include <stdlib.h>
#include "stackWORD.h"
#include "stackCLASS.h"

#define CLASS_LINE '+'
#define WORD_LINE '-'
#define TIPS_DELIMITER ','

//inicia a cabeca da nossa PILHA
void start_stackClass(CLASS_MY *HEAD_CLASS)
{
    HEAD_CLASS->upClass = NULL;  
	
	start_stackWord(HEAD_CLASS->word_head);
}

//Verifica se a PILHA esta vazia
//0 -> SIM
//1 -> NAO
int chk_empty_stackClass(CLASS_MY *STACK_CLASS)
{
    if(STACK_CLASS->upClass == NULL)
        return 0;
    else
        return 1;
}

//Aloca um novo NODE de categoria, 
//atribui o nome ao NODE
//e retorna
CLASS_MY *allocateClass(char *className)
{
    CLASS_MY *NEW = (CLASS_MY *) malloc(sizeof(CLASS_MY));
    if(!NEW)
    {
        printf("[ERROR 0]: %s", ERRORS[0]);
        
        system("PAUSE>>NULL");
        return NULL;
    }
    
    NEW->className = strdup(className);

    return NEW;   
}

//colocar uma nova categoria na pilha de categorias
void pushClass(CLASS_MY *STACK_CLASS, char *className)
{
    CLASS_MY *NEW = allocateClass(className);//aloquei uma nova categoria
    NEW->word_head = (WORD_MY*) malloc(sizeof(WORD_MY));//aloquei a cabeca de palavras da categoria
	NEW->upClass = NULL;
	NEW->word_head->upWord = NULL;
	
    if(STACK_CLASS->upClass == NULL){
        STACK_CLASS->upClass = NEW;
	}else{
        CLASS_MY *aux = (CLASS_MY *) malloc(sizeof(CLASS_MY));
        
        aux->upClass = STACK_CLASS->upClass;
        while(aux->upClass != NULL)
            aux = aux->upClass;   
            
        aux->upClass = NEW; 
    }    
}

void pushWord_in_stackClass(CLASS_MY *STACK_CLASS, char *name, char *tip1, char *tip2, char *tip3)
{
	/*
		essa funcao aloca um novo NODE de palavra para a PILHA de categoria
		passa esse NODE criado para a ultima palavra da PILHA

		ou da um push em um NODE de palavra ;)
	*/	
	//criando o NODE com a palavra da determinada categoria
 
	CLASS_MY *aux = STACK_CLASS;

	//primeiro percorrer ate o ultimo NODE de STACK_CLASS
	while(aux->upClass != NULL)
	{	
		aux = aux->upClass;	
	}

	//enviar a PILHA de palavras no ultimo NODE da PILHA de categorias
	pushWord(aux->word_head, name, tip1, tip2, tip3);
}

//retorna quantos nos tem a PILHA
//nao conta com a cabeca
int classAmount(CLASS_MY *STACK_CLASS)
{
    int nodesTotal = 0;
    CLASS_MY *aux = STACK_CLASS;
    
    while(aux->upClass != NULL)
    {
        nodesTotal++;
        aux = aux->upClass;
    }
       
    return nodesTotal;   
}

//procura pelo NODE especifico   (num) na pilha
//retorna o NODE especifico se for menor doq a quantidade total de nodes
CLASS_MY *search_classNode(CLASS_MY *STACK_CLASS, int numNode)
{	
	if((chk_empty_stackClass(STACK_CLASS)) && (numNode <= classAmount(STACK_CLASS)))
	{
		CLASS_MY *aux = STACK_CLASS->upClass;
		int i;
		for(i = 0; i < numNode-1; i++)
			aux = aux->upClass;

		return aux;
	}else
		return NULL;
}

//function that reads the Data on the archive 
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
