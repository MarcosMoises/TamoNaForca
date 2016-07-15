#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define HEADER_LINE '+' 
#define WORD_LINE '-'

typedef struct word
{
	char *nome;
	char *tips[3];
}WORD_MY;

void setWords();

int main()
{
	setWords();
	return 0;
}

void setWords()
{
	char inputCH, inputCateg[50], inputWord[50], inputTips[3][50];
	char url[] = "palavras.txt";
	
	FILE *arq = fopen(url, "r");
	if(arq == NULL)	
	{
		printf("[ERRO 0]: nao foi possivel abrir o arquivo");
		getch();
		exit(1);
	}
	
	do
	{
		//Ler o codigo do inicio da linha
		inputCH = fgetc(arq);
		if(inputCH == HEADER_LINE){
			//lendo a categoria
			fscanf(arq, "%[^\n]s", inputCateg);
			inputCH = fgetc(arq);
			printf("\n\ncategoria: %s", inputCateg);
		}
		else if(inputCH == WORD_LINE){
			//lendo uma palavra da categoria
			fscanf(arq, "%[^,]s", inputWord);
			inputCH = fgetc(arq);
			//lendo as dicas
			fscanf(arq, "%[^,]s", inputTips[0]);
			inputCH = fgetc(arq);
			fscanf(arq, "%[^,]s", inputTips[1]);
			inputCH = fgetc(arq);
			fscanf(arq, "%[^\n]s", inputTips[2]);
			inputCH = fgetc(arq);

			printf("\n%s[dica 1: %s][dica 2: %s][dica 3: %s]", inputWord, inputTips[0], inputTips[1], inputTips[2]);
			getch();
		}
	}while(inputCH != EOF);
}
