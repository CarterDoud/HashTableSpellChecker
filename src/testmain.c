#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "word.h"

int main()
{
	HTable* testTable = createTable(100,*hashNode,*deleteWord,*printWord);
	char* testWord1 = "test";
	char* testWord2 = "test2";
	int key1;
	int key2;
	printf("testing insertData\n");
	key1 = stringKey(testWord1);
	key2 = stringKey(testWord2);
	Word *w1 = createWord(testWord1);
	Word *w2 = createWord(testWord2);
	printf("using word %s using key %d\n",testWord1,key1);
	printf("using word %s using key %d\n",testWord2,key2);
	insertData(testTable, key1, w1);
	
	insertData(testTable,key2,w2);
	printf("testing printTable\n");
	printTable(testTable);
	printf("Expected output\n");
	printf("%d:%d: %s\n",hashNode(100,key1),key1,testWord1);
	printf("%d:%d: %s\n",hashNode(100,key2),key2,testWord2);
	printf("testing lookupData\n");
	printf("looking up key %d\n",key1);
	printf("%s\n",getWord(lookupData(testTable,key1)));
	printf("expected output\n");
	printf("%s\n",testWord1);
	printf("testing removeData\n");
	printf("removing word %s\n",testWord1);
	removeData(testTable,key2);
	printTable(testTable);
	printf("expected output\n");
	printf("%s\n",testWord1);
}