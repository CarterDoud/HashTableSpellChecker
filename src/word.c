/**
 * @file word.c
 * @author Carter Doud
 * @date November 2017
 * @brief File containing the function definitions for word structs
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

char *strdup (const char *s) {
    char *d = malloc (strlen (s) + 1);   
    if (d == NULL) return NULL;          
    strcpy (d,s);                        
    return d;   
}
Word* createWord(char* word)
{
	Word* tmp;
	tmp=( Word *)malloc(sizeof( Word));
	tmp->value=strdup(word);
	return tmp;
}
const char* getWord(Word* w)
{
	return w->value;
}
void printWord(void* w)
{
	printf("%s\n",getWord(w));
}
void deleteWord(void*w)
{
	free(w);
}