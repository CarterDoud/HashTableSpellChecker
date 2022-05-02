/**
 * @file word.h
 * @author Carter
 * @date November 2017
 * @brief File containing the function definitions of a word struct
 */
#ifndef WORD_H
#define WORD_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* word structure
**/
typedef struct word{
	char *value;
}Word; 

/**Function to create a word. Allocates memory to the struct
*@return pointer to a word
*@param word string of characters for the value of the struct
**/
Word* createWord(char* word);

/**Function to duplicate a string
*@return a copy of a string
*@param s string to duplicate
**/
char *strdup (const char *s);

/**Function to return the value of a word struct
*@return string value of the word
*@param w a word with a string value
**/
const char* getWord(Word* w);

/**Function to print the value of a word struct
*@param w a word with a string value
*@post prints the value of the word to stdout
**/
void printWord(void* w);

/**Function to delete a word struct
*@param w a word with a string value
*@post deletes w
**/
void deleteWord(void*w);
#endif