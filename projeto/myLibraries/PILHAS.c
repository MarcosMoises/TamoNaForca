#include <stdio.h>
#include <stdlib.h>
#include "PILHAS.h"
#include "databaseCODES\\stackWORD.h"

//inicia a cabeca da nossa PILHA
void iniciar(NODE *HEAD_PILHA)
{
    HEAD_PILHA->prox = NULL;  
}

//Verifica se a PILHA esta vazia
//0 -> SIM
//1 -> NAO
int vazio(NODE *PILHA)
{
    if(PILHA->prox == NULL)
        return 0;
    else
        return 1;
}

//Aloca um novo NODE, 
//atribui o valor ao char
//e retorna
NODE *aloca(int numb)
{
    NODE *novo = (NODE *) malloc(sizeof(NODE));
    if(!novo)
    {
        printf("[ERROR 0]: %s", ERRORS[0]);
        
        system("PAUSE>>NULL");
        exit(1);
    }
    
    novo->num = numb; 
    
    return novo;   
}

//colocar um novo elemento na pilha
void push(NODE *PILHA, int numb)
{
    NODE *novo = aloca(numb);
    novo->prox = NULL;
    
    if(PILHA->prox == NULL)
        PILHA->prox = novo;
    else
    {
        NODE *aux = (NODE *) malloc(sizeof(NODE));
        
        aux->prox = PILHA->prox;
        while(aux->prox != NULL)
            aux = aux->prox;   
            
        aux->prox = novo; 
    }    
}

//retirar o ultimo elemento da pilha
//e retorna-lo
NODE *pop(NODE *PILHA)
{
    if(!vazio(PILHA))
    {
        return NULL;   
    }else{
        NODE *ultimo = PILHA->prox,
             *penultimo = PILHA;
             
        while(ultimo->prox != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;       
        }
        
        penultimo->prox = NULL;
        return ultimo;
    }       
}

//exibe o conteudo de cada NODE
void showNodes(NODE *PILHA)
{
    if (vazio(PILHA))
    {
        NODE *aux = PILHA->prox;
        
        while(aux != NULL)
        {
            int ptr = aux->num;
            printf("%c ", ptr);   
            aux = aux->prox;
        }
    }
}

//retorna quantos nos tem a PILHA
//nao conta com a cabeca
int nodesAmount(NODE *PILHA)
{
    int tamanhoDaPilha = 0;
    NODE *aux = PILHA;
    
    while(aux->prox != NULL)
    {
        tamanhoDaPilha++;
        aux = aux->prox;
    }
       
    return tamanhoDaPilha;   
}

//procura pelo NODE com o inteiro pela PILHA
NODE *search_int(NODE *PILHA, int num)
{
	if(vazio(PILHA))
	{
		NODE *aux = PILHA->prox;
		while(aux != NULL)
		{
			if(aux->num == num)
				return aux;
			aux = aux->prox;
		}
	}else
		return NULL;
}

//libera o corpo da PILHA
//deixando a cabeca
void liberaCorpo(NODE *PILHA)
{
    if(vazio(PILHA))
    {
        NODE *atualNode,
               *proxNode;
        
        atualNode = PILHA->prox;
        while(atualNode != NULL)
        {
            proxNode = atualNode->prox;
            free(atualNode);      
            atualNode = proxNode;
        }
        
        PILHA->prox = NULL;
    }
}
