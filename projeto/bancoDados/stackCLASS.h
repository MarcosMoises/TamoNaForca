#ifndef STACKCLASS_H
#define STACKCLASS_H

typedef struct my_class
{
	char *className;//o nome da categoria
	WORD_MY *word_head;//uma PILHA para as palavras dessa categoria
	struct my_class *upClass;
}CLASS_MY;

void start_stackClass(CLASS_MY*);

int chk_empty_stackClass(CLASS_MY*);

void pushClass(CLASS_MY*, char*);

void pushWord_in_stackClass(CLASS_MY*, char*, char*, char*, char*);//4 strings: 1 name and 3 tips

int classAmount(CLASS_MY*);

CLASS_MY *search_classNode(CLASS_MY *STACK_CLASS, int numNode);

#endif
