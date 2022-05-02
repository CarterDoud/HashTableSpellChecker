/**
 * @file main.c
 * @author Carter Doud
 * @date November 2017
 * @brief spellchecker implemented with a hashmap
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "word.h"
int main(int argc, char *argv[])
{
	FILE* fileTemp = NULL;
	FILE* fileIn = NULL;
	int fileWordCount = 0;
	int matches = 0;
	int misMatch = 0;
	char newWord[64];
	int quit=0;
	int choice;
	int key;
	char dataString [64];
	char fileCheck[255];
	HTable* testTable = createTable(100,*hashNode,*deleteWord,*printWord); // dummy functions
	if (argc != 2)
		{
			//exits program if incorrect number of command line args are entered
			exit(0);
		}
		fileTemp = fopen(argv[argc-1], "r+");
		if (fileTemp == NULL)
		{
			printf("File Empty\n");
			exit(0);
			//checks if file is empty        
		}
		while (fgets(dataString, 155, fileTemp) != NULL)
		{
			sscanf(dataString,"%63s",newWord);
			key = stringKey(newWord);
			Word *w = createWord(newWord);
			insertData(testTable,key,w);
			fileWordCount++;
			//hash stuff, add to table
		}
		//printf("1.Insert a new word\n");
		while(quit==0)
		{
			printf("1.Insert a new word\n");
			printf("2.Remove a word\n");
			printf("3.Spell Check a file\n");
			printf("4.Show dictionary words\n");
			printf("5.Quit\n");
			printf("Enter your choice:");     
			scanf("%d",&choice);
			(void)getchar();
			switch(choice)
			{
				case 1:
				
					printf("enter word\n");
					scanf("%63s",newWord);
					key = stringKey(newWord);
					Word *w = createWord(newWord);
					if(lookupData(testTable,key)!=NULL)
					{
						if(strcmp(getWord(lookupData(testTable,key)),newWord)==0)
						{
							printf("Duplicate word failed to add to dictionary\n");
						}
					}
					else
					{
						printf("Succsessfully added to dictionary\n");
						insertData(testTable,key,w);
					}
					//printWord(w);
					//printf("index: %d key:%d\n",test2,test);
					
					//scanf("%*s");
					//printElement(testTable,lookupData(testTable,key));
					//printNodeData(testTable,test);
				break;
				case 2:
					printf("enter word\n");
					scanf("%63s",newWord);
					key = stringKey(newWord);
					if(lookupData(testTable,key)!=NULL)
					{
						if(strcmp(getWord(lookupData(testTable,key)),newWord)==0)
						{
							printf("delete\n");
							//deleteWord(lookupData(testTable,key));
							removeData(testTable,key);
						}
					}
					else
					{
						printf("Word not found\n");
						
					}
					
				break;
				case 3:
					printf("enter a filename\n");
					scanf("%255s",fileCheck);
					fileIn = fopen(fileCheck, "r+");
					if (fileIn == NULL)
					{
						printf("File Does not exist\n");
						break;
						//checks if file is empty        
					}
					printf("File Processed: fileCheck\n");
					while (fgets(dataString, 155, fileIn) != NULL)
					{
						sscanf(dataString,"%63s",newWord);
						key = stringKey(newWord);
						if(strcmp(getWord(lookupData(testTable,key)),newWord)==0)
						{
							//printf("words are the same\n");
							matches++;
						}
						else
						{
							printf("%s not found in dictionary\n",newWord);
							misMatch++;
						}
					}
					printf("Correctly spelt words: %d\n",matches);
					printf("Incorrectly spelt words: %d\n",misMatch);
				break;
				case 4:
					printTable(testTable);
					/*for(i=0;i<testTable->size;i++)
					{
						//printf("%d\n",i);
						if(lookupData(testTable,i))
						{
							//printf("here\n");
							printElement(testTable,lookupData(testTable,i));
						}
					}*/
				break;
				case 5:
					exit(0);
				break;
				default:
					
					printf("Invalid choice, please try again\n");
					
				break;
			}
			
		}
}
