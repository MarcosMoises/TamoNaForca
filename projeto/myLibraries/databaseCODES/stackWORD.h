#ifndef STACKWORD_H
#define	STACKWORD_H


extern const char *ERRORS[];

typedef struct word
{
	char *name;
	char *tips[3];
	struct word *upWord;
}WORD_MY;


void start_stackWord(WORD_MY*);

int chk_empty_stackWord(WORD_MY*);

WORD_MY *allocateWord(char*, char*, char*, char*);
void pushWord(WORD_MY*, char*, char*, char*, char*);

void add_stackWord_with_info(WORD_MY*);

void showWords(WORD_MY*);

int wordsAmount(WORD_MY*);

WORD_MY *search_wordNode(WORD_MY*, int);

void printWord_Pos(WORD_MY*, int);

void free_stackBody(WORD_MY*);

#endif
