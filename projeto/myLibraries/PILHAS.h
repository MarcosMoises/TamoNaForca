#ifndef LIBRARY_H
#define LIBRARY_H

struct Node
{
    int num;
    struct Node *prox;    
}typedef NODE;

void iniciar(NODE*);
int vazio(NODE*);
NODE *aloca(int);
void push(NODE*, int);
NODE *pop(NODE*);
void showNodes(NODE*);

int nodesAmount(NODE*);

NODE *search_int(NODE*, int);

void liberaCorpo(NODE*);


#endif
