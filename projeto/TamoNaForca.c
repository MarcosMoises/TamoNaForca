/*  Projeto: TamoNaForca
	
	descricao: criar o jogo da forca em C

	dataDeInicio: 29/05/2015

	componentes: Moises
	pre-componentes: Yuri, Eloiza, Andryele
	
	updates atuais: ->Terminar a exibicao completa do Menu
					--*Exibir as instrucoes com switch-case1-case0	
					
					-->compatibilidade com o tamanho da tela do DOS(120x60)
					----*criar a funcao de setar o tamanho da tela
					-----*criar uma biblioteca "dosHelper.h"
					
					->Transformar o codigo em algo mais legível
  */

#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "myLibraries\\wordHelper.h"
#include "myLibraries\\PILHAS.h"
#include "myLibraries\\databaseCODES\\stackCLASS.h"
#include "myLibraries\\databaseCODES\\stackWORD.h"
#include "myLibraries\\layout\\windowsHELPER.h"
#include "myLibraries\\helpers\\stringHELPER.h"
#include "drawHelper.h"

#define DOS_SIZE_HEIGHT 20
#define DOS_SIZE_WIDTH 80

//regra dos errors : muda de acordo com o tamanho de "nome" nas estruturas
int errorsLaw = START_WORD;

char menuPrincipal (); /* menu principal, retorna a opcao */


char menuIniciar();/*	submenu do menuPrincipal,
						nesse menu será escolhido as categorias para a palavra
						*/

char menuInstrucoes();/*submenu do menuPrincipal,
						nesse menu será exibido as instrucoes
						*/

char menuSobre();/*	submenu do menuPrincipal,
					nesse menu será exibido as informacoes do jogo e desenvolvedores
					*/

CLASS_MY* randomly_select_class(CLASS_MY* head_class);/*
									seleciona randomicamente um NODE da pilha head_class
									retorna esse NODE
									*/

WORD_MY_AUX *randomly_select_word(CLASS_MY* head_class);/*
												seleciona randomicamente(de acordo com a categoria) um NODE WORD_MY em head_class
												retorna o NODE selecionado
												*/

void setup_the_game(WORD_MY_AUX *random, int *errorsLimit);/*muda as configuracoes de jogo de acordo com o tamanho de "random->name" */

void playGame(CLASS_MY *head_class);/*funcao para jogar
								de acordo com a categoria escolhida, ira configurar o jogo
								*/
int main() 
{	
	set_DOS_size(DOS_SIZE_HEIGHT,DOS_SIZE_WIDTH);
	
	char opcao, opcao_submenu;//opcoes para escolhas de opcao nos menus

	//pilhas que irao guardar o conteudo lido no arquivo "bancoDados.txt"
	CLASS_MY *class_head = (CLASS_MY*)malloc(sizeof(CLASS_MY));//Pilha de categoria
	class_head->word_head = (WORD_MY*)malloc(sizeof(WORD_MY));//Pilha de palavras
	
	start_stackClass(class_head);
	
	readFile_setClasses(class_head);//funcao que ira ler "bancoDados.txt" e salvar em class_head
	                                //a funcao separar todas as categorias e as palavras de categoria
	                                //ela le uma categoria, as palavras da palavra e as 3 dicas da palavra

	do 
	{
		system("CLS");
		
		opcao = menuPrincipal();

		system("CLS");
	
		switch(opcao) 
		{
		
			//Iniciar Jogo////////////////////////////////////////////
			case '1':
				opcao_submenu = menuIniciar();//Por enquanto sem utilidades
				system("CLS");
				playGame(class_head);
				break;
			//Instrucoes//////////////////////////////////////////////
			case '2':
				menuInstrucoes();
				printf("\nPressione qualquer tecla para voltar: ");
				getch();
				break;
			//Sobre////////////////////////////////////////////////////
			case '3':
				menuSobre();
				printf("\nPressione qualquer tecla para voltar: ");
				getch();
				break;
			//Sair//////////////////////////////////////////////////////
			case '0':
				break;
		}
	} while (opcao != '0');


	getch();
	return 0;
}

char menuPrincipal () 
{
	char opPrincipal;//opcao do menu principal	

	do 
	{
		system("CLS");
		printf("-------------------MENU PRINCIPAL--------------------\n");

		printf("|                 1 - Iniciar Jogo                   |\n");
		printf("|                 2 - Instrucoes                     |\n");
		printf("|                 3 - Sobre                          |\n");
		printf("|                 0 - Sair                           |\n");
		printf("------------------------------------------------------\n");
		printf("|                  OPCAO:                            |\n");
		printf("------------------------------------------------------\n\n");

		opPrincipal = getch();
		
		if (opPrincipal >= '0' && opPrincipal <= '3') 
		{ //se o usuario digitar um numero e for de 0,1,2 ou 3, vai retornar
			return opPrincipal;
		}
		else 
		{
			system("CLS");
			Beep(2500, 220);//som do erro
			printf("[ERRO]:valor informado nao foi reconhecido pelo sistema!");
			printf("\nPressione qualquer tecla para prosseguir");
			getch();
		}
	}while (1);

}

char menuIniciar(){

	char opCategoria;//opcao do menu Inciar Jogo(das categorias)

	do
	{
		system("CLS");

		printf("---------------SORTEANDO CATEGORIA---------------\n");
		printf("-----------------------------------------------\n");
		printf("-----------------------------------------------\n");
		opCategoria = getch();

		if (opCategoria >= '0' && opCategoria <= '9') 
		{ 
			return opCategoria;
		}
		else 
		{
			system("CLS");
			Beep(2500, 220);//som do erro
			printf("[ERRO]:valor informado nao foi reconhecido pelo sistema!");
			printf("\nPressione qualquer tecla para prosseguir");
			getch();
		}
	}while (1);


	return opCategoria;
}

char menuInstrucoes(){
	printf("-----------------------------------INSTRUCOES-----------------------------------\n\n");

	/*
	cout << "1 -> Como jogar\n";
	cout << "2 -> Regras Gerais\n";
	cout << "3 -> Modos de jogo\n";
	cout << "4 -> Regras das dicas";
	*/

	printf("-> Como jogar:.................................................................. \n"); // primeiro
	printf("    O jogo comecara com a palavra a ser adivinhada, representada por tracinhos:\n\n");
	printf("    Ex:.'MAX', se escreve:  _ _ _ \n\n");
	printf("    e o jogador que tenta adivinhar deve ir digitando as letras que podem\n");
	printf(" existir  na palavra.\n");
	printf("    Quando o jogador digitar uma letra e a mesma fizer parte da palavra, sera\n substituida no tracinho:\n\n");
	printf("    Ex:.'MAX'               M _ _\n");
	printf("................................................................................ \n\n");
 
	printf("-> Regras gerais:............................................................... \n");
	printf("    Quando for digitar a letra da palavra, esta proibido\n\n");
	printf("    *********repetir letras\n");
	printf("    *********digitar duas letras de uma so vez\n\n");
	printf("    caso isso aconteca, contara como erro e perdera 1 ponto.\n\n");
	printf("................................................................................ \n\n");

	printf("-> Modos de jogo:............................................................... \n");
	printf("    1 jogador:\n");
	printf("       O enforcado escolhera uma categoria e o jogo vai sortear a palavra.\n");
	printf("    2 jogadores: \n");
	printf("       O jogador digitara a devida palavra e as dicas referentes, que serao \n mostradas logo abaixo, para seu adversario tentar acertar.\n\n"); 
	printf("................................................................................ \n\n");

	printf("-> Regras das dicas:.......................................................... \n\n");
	printf("    Em todas as palavras, serao disponibilizadas 3 dicas, que dependem dos\n erros cometidos e tamanho da palavra: \n\n");
	printf("    ***se a palavra for de 1 a 6 letras: no 1 erro, exibira a 1 dica, no 4,\n exibira a 2 dica, e se passar da metade do total de erros permitidos,\n exibira a ultima dica.\n");
	printf("       O jogador, nesse caso, podera errar 7 vezes.\n\n");
	printf("    ***se a palavra for de 7 a 13 letras: no 1 erro, exibira a 1 dica, no 3,\n exibira a 2 dica, e se passar do 4, exibira a ultima dica.\n");
	printf("       O jogador, nesse caso, podera errar 5 vezes.\n\n");
	printf("    ***se a palavra for igual, ou maior que 14 letras: no 1 erro, exibira a\n 1 dica, no 2, exibira a 2 dica, e no 3, exibira a ultima dica.\n\n");
	printf("       O jogador, nesse caso, podera errar 4 vezes.\n");
	printf("................................................................................ \n\n");
	
}

char menuSobre(){
	//exibe informoes sobre Jogo e Desenvolvedores
	printf("O jogo TamoNaForca foi criado no ano de 2015 por um grupo de alunos do segundo \nano de informatica integrado do INSTITUTO FEDERAL DE EDUCACAO, CIENCIA E TECNOLOGIA DO RIO GRANDE DO NORTE - Campus Caico. ");
	printf("Criado na IDE DEVC++, utilizando a linguagem de programacao C++\n");
    printf("versao 0.1");
    printf("\n\n\t<CRIADORES> \n\tMarcos Moises");
	printf("\n\n\t<ORIENTADOR> \n\tMax Miller\n\n");
}

//seleciona randomicamente uma das categorias e retorna a categoria selecionada
CLASS_MY* randomly_select_class(CLASS_MY* head_class)
{ 
	int randomPosition = (rand() % classAmount(head_class))+1;

	CLASS_MY *aux = search_classNode(head_class, randomPosition);
		
	return aux;
}

//seleciona randomicamente um dos NODES de palavras dentro da PILHA de categorias "head_class" 
WORD_MY_AUX *randomly_select_word(CLASS_MY *head_class)
{
	int randomPosition = (rand() % wordsAmount(head_class->word_head))+1;//sorteando uma posicao na PILHA de palavras

	WORD_MY *randomicWordAux;
	WORD_MY_AUX *randomicWord;

	//ponteiro randomicWordAux aponta para NODE de palavras sorteado aleatoriamente
	randomicWordAux = search_wordNode(head_class->word_head, randomPosition);
	
	//ponteiro temporario que irá salvar as informacoes que randomicWordAux aponta
	randomicWord = create_Word(randomicWordAux->name, randomicWordAux->tips[0], randomicWordAux->tips[1], randomicWordAux->tips[2]);
	
	return randomicWord;
}

//iniciar as regras basicas do jogo
void setup_the_game(WORD_MY_AUX *random, int *errorsLimit)
{
	//verificar qual o padrao de erros que deve ser adotado
	errorsLaw = word_Length(random);

	//setar o limite de erros de acordo com a regra das erros
	switch(errorsLaw)
	{
		case SMALL_WORD:
			*errorsLimit = 7;
			break;
		case MEDIUM_WORD:
			*errorsLimit = 5;
			break;
		case LONG_WORD:
			*errorsLimit = 4;
			break;
	}

}

void playGame(CLASS_MY *head_class)
{
	//criando estrutura para receber uma outra estrutura de palavra aleatoria
	WORD_MY_AUX *random;
	char *randomNameAux[2];
	/*
		vetor com o primeiro ponteiro com uma copia do nome da palavra sorteada(random->name)
		o segundo ponteiro eh de 0,1
		se for 0, nao exibe, se for 1 exibe
		EX.: H E L L O -randomNameAux[0]
			 0 0 1 1 0 -randomNameAux[1]
		SAIDA.: _ _ L L _
	*/
	int errorsTotal = 0;
	int errorsLimit;
	bool endGame = false;
	bool validInput = false;
	bool incrementError = false;

	//sortear palavra
	srand((unsigned int)time(NULL));//deixar mais randomica o "random() % x"
	
	CLASS_MY *stack_class_aux = randomly_select_class(head_class);//PILHA que ira receber uma categoria sorteada randomicamente
	
	random = randomly_select_word(stack_class_aux);//selecionar uma palavra na categoria randomicamente e atribuir a random
	
	//setar as configuracoes de regras de erro de acordo com a palavra sorteada
	setup_the_game(random, &errorsLimit);

	//iniciar o nome auxiliar randomNameAux[0] com a palavra
	//iniciar randomNameAux[1] com 0s
	start_Name_Aux(random, randomNameAux);
	
	NODE *Inputs = (NODE *)malloc(sizeof(NODE));
	iniciar(Inputs);
	do
	{
		system("cls");
		
		printf("categoria: %s\n", stack_class_aux->className);
		
		drawnGallow(errorsTotal, errorsLimit);//desenhar a forca de acordo com o total de erros
		
		printf("Total de erros: %d/Limite: %d\n\n", errorsTotal, errorsLimit);
		
		show_Tips(random, errorsTotal, errorsLimit);//exibir as dicas dentro de random
		                                            //de acordo com o total de erros
		
		printf("\n\nPalavra: ");
		show_Name_Aux(randomNameAux);//exibir a palavra
		                             //0-> nao exibe 1->exibe
	
		printf("\n\nInforma uma letra: ");
		printf("{");
		showNodes(Inputs);//exibe as letras já informadas
		printf("}");
		char InputCH = getch();
		
		//verificando a entrada do usuario
		if(chk_Input_Inputs(Inputs, InputCH))
		{
			incrementError = true;
		}else
		{
			//checa qual foi a entrada
			int chkResult = chk_Input_nameAux(InputCH,  randomNameAux);
			switch(chkResult)
			{					
				//input novo
				//mas nao pertence as letras da palavra
				case 0:	
					incrementError = true;
					break;
	
				//input valido
				//o input nao foi informado ainda e pertence a palavra
				case 1:
					delete_CH_nameAux(InputCH, randomNameAux);  
					break;

				//input invalido
				//já foi informado um input de mesmo valor
				case 2:
					incrementError = true;
					break;
			}					
			
			push(Inputs, InputCH);//coloca InputCH na pilha de chars de Inputs

		}

		if(incrementError == true)
		{
			if(errorsTotal > errorsLimit-2)
			{
				endGame = true;
				errorsTotal++;
				break;
			}
			errorsTotal++;
			incrementError = false;
		}

		//funcao que checa se toda a palavra ja foi preenchida
		if(chk_allInvalid_nameAux(randomNameAux))
			endGame = true; 
			
	}while(!endGame);

	system("cls");
	printf("FIM DE JOGO\n");
	if(errorsTotal == errorsLimit)
	{
		printf("VOCE EH UM PERDEDOR, SABE NEM AS PALAVRAS OTARIO\n");
		drawnGallow(errorsTotal, errorsLimit);
	}else
		printf("VOCE GANHOU\n\n\n");
	printf("Total de erros: %d/Limite: %d\n\n", errorsTotal, errorsLimit);
	printf("Palavra: %s", randomNameAux[0]);
	liberaCorpo(Inputs);
	free(random);
	getch();
}
