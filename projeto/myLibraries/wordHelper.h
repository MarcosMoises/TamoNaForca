#ifndef WORDHELPER_H
#define WORDHELPER_H

#include "PILHAS.h"

#define START_WORD 0
#define SMALL_WORD 1
#define MEDIUM_WORD 2
#define LONG_WORD 3

typedef struct wordAtributes
{
	char *name;
	char *tips[3];
}WORD_MY_AUX;

WORD_MY_AUX *create_Word(char *, char *, char *, char *);

int chk_Word_empty(WORD_MY_AUX*);

char *check_Char_Word(WORD_MY_AUX*, char);
int word_Length(WORD_MY_AUX*);

void start_Name_Aux(WORD_MY_AUX*, char*[]);
void show_Name_Aux(char*[]);
void show_Tips(WORD_MY_AUX*, int, int);

void freeWordStack(WORD_MY_AUX*);

int chk_Input_Inputs(NODE *, char);
int chk_CH_nameAux(char, char*[]);
void delete_CH_nameAux(char, char*[]);

int chk_allInvalid_nameAux(char*[]);


#endif
