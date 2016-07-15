/*
	pushWord need to be fixed, because its changing the address of a struct
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pilhaPALAVRAS.h"

const char *ERRORS[] = {
	"low memory avaiable",
	"empty stack"
};

//inicia a cabeca da nossa PILHA
void start_stackWord(WORD_MY *HEAD_STACK)
{
    HEAD_STACK->upWord = NULL;  
}

//Verifica se a PILHA esta vazia
//0 -> SIM
//1 -> NAO
int chk_empty_stackWord(WORD_MY *STACK_WORD)
{
    if(STACK_WORD->upWord == NULL)
        return 0;
    else
        return 1;
}

//Aloca um novo NODE, 
//atribui o nome e os tipos ao NODE
//e retorna

//O PROBLEMA TALVEZ SEJA O PUSH WORD
WORD_MY *allocateWord(char *name, char *tip1, char *tip2, char *tip3)
{
    WORD_MY *NEW = (WORD_MY *) malloc(sizeof(WORD_MY));
    if(!NEW)
    {
        printf("[ERROR 0]: %s", ERRORS[0]);
        
        system("PAUSE>>NULL");
        return NULL;
    }
    
    NEW->name = strdup(name);
	NEW->tips[0] = strdup(tip1);
	NEW->tips[1] = strdup(tip2);
	NEW->tips[2] = strdup(tip3);

    return NEW;   
}

//put a new word at the end of the stack of words
//the function need to be fixed, because it`s changing the Address of the word struct
void pushWord(WORD_MY *STACK_WORD, char *name, char *tip1, char *tip2, char *tip3)
{
    WORD_MY *NEW = allocateWord(name , tip1, tip2, tip3);
	NEW->upWord = NULL;

	if(STACK_WORD->upWord == NULL){
        STACK_WORD->upWord = NEW;
	}else{
        WORD_MY *aux = (WORD_MY *) malloc(sizeof(WORD_MY));
        
        aux->upWord = STACK_WORD->upWord;
        while(aux->upWord != NULL)
            aux = aux->upWord;   
            
        aux->upWord = NEW; 
    }   
}

//its a implemetation of void pushWord(...)
//here the function ask what values you want to put in a new NODE of STACK_WORD
void add_stackWord_with_info(WORD_MY *STACK_WORD)
{
	char name[30], tips[3][30];	

	printf("name: ");
	scanf("%[^\n]s", name);
	int i;
	for(i = 0; i < 3; i++)
	{
		printf("tip %d: ", i+1);
		scanf(" %[^\n]s", tips[i]);
	}

	pushWord(STACK_WORD, name, tips[0], tips[1], tips[2]);
}

//show the content of every STACK of words
void showWords(WORD_MY *STACK_WORD)
{
    if (chk_empty_stackWord(STACK_WORD))
    {
        WORD_MY *aux = STACK_WORD->upWord;
        
        while(aux != NULL)
        {
			char *name = aux->name;

			char *tip1 = aux->tips[0];   
			char *tip2 = aux->tips[1];
			char *tip3 = aux->tips[2];

			printf("\nPALAVRA: %s\ndica 1: %s\ndica 2: %s\ndica 3: %s", aux->name, tip1, tip2, tip3);   
            aux = aux->upWord;
        }
    }
}

//count the amount of Words in the STACK
int wordsAmount(WORD_MY *STACK_WORD)
{
    int nodesTotal = 0;
    WORD_MY *aux = STACK_WORD->upWord;
    
    while(aux != NULL)
    {
        nodesTotal++;
        aux = aux->upWord;
    }
       
    return nodesTotal;   
}

//procura pelo NODE especifico   (num) na pilha
//retorna o NODE especifico se for menor menor doq a quantidade total de nodes
WORD_MY *search_wordNode(WORD_MY *STACK_WORD, int numNode)
{	
	if((chk_empty_stackWord(STACK_WORD)) && (numNode <= wordsAmount(STACK_WORD)))
	{
		WORD_MY *aux = STACK_WORD->upWord;
		int i;
		for(i = 0; i < numNode; i++)
			aux = aux->upWord;

		return aux;
	}else
		return NULL;
}


void printWord_Pos(WORD_MY *STACK_WORD, int WORDposition)
{
	WORD_MY *aux;
	aux = search_wordNode(STACK_WORD, WORDposition);

	printf("\npalavra: %s", aux->name);
	printf("\ndica 1: %s", aux->tips[0]);
	printf("\ndica 2: %s", aux->tips[1]);
	printf("\ndica 2: %s", aux->tips[2]);
}

//free the memory of the STACK`s body
void free_stackBody(WORD_MY *STACK_WORD)
{
    if(chk_empty_stackWord(STACK_WORD))
    {
        WORD_MY *nowNode,
               *upNode;
        
        nowNode = STACK_WORD->upWord;
        while(nowNode != NULL)
        {
            upNode = nowNode->upWord;
            free(nowNode);      
            nowNode = upNode;
        }
        
        STACK_WORD->upWord = NULL;
    }
}
