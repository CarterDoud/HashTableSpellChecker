/**
 * @file HashTableAPI.c
 * @author Carter Doud
 * @date November 2017
 * @brief File containing the function definitions of a hash table
 */
#include <stdio.h>
#include <stdlib.h>
#include "HashTableAPI.h"
#include "word.h"

HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted))
{
	HTable* tmp = malloc(sizeof (HTable));
	
	if(tmp!=NULL)
	{
		tmp->hashFunction=hashFunction;
		tmp->printNode=printNode;
		tmp->destroyData=destroyData;
		tmp->size = size;
		tmp->table = (Node**)malloc(sizeof(Node*) * size);
		/*for(i=0;i<size;i++)
		{
			tmp->table[i]->data=NULL;
		}*/
	}
	//Node ** table = malloc(sizeof(Node)*size;
		//tmp = (List*)malloc(sizeof(List));
	
	//int i = 0;
	// Initialize all values in table to 0
	/*for( i = 0; i < TABLE_SIZE;i++)
	{
		table[i] = 0;
	}*/
	return tmp;
}
Node *createNode(int key, void *data)
{
	Node* tmp;
	tmp=( Node *)malloc(sizeof( Node));
	tmp->data = data;
	tmp->key=key;
	tmp->next=NULL;
	return tmp;
}
int stringKey(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		r =r + str[i]*i+1;
	}
	//r =  r%100;
	return r;
}
void insertData(HTable *hashTable, int key, void *data)
{
	Node* tmp;
	int index;
	tmp=( Node *)malloc(sizeof( Node));
	tmp = createNode(key,data);
	index = hashNode(hashTable->size,key);
	//if index is empty
	if(!hashTable->table[index])
	{
	//	printf("new word\n");
		hashTable->table[index] = tmp;
	}
	// if there is a collision
	else
	{
		//printf("collision\n");
		hashTable->table[index]->next = tmp;
	}
	//hashTable->table[index] = tmp;
}
int hashNode(size_t tableSize, int key)
{
	//returns a value less than the table size
	return key%tableSize;
}
void printTable(HTable *hashTable)
{
	int i;
	int index;
	printf("Index  Key  Value\n");
	for(i=0;i<hashTable->size;i++)
	{
		index = i;
		if(hashTable->table[index]==NULL)
		{
			
			//if index has no data
		}
		else
		{
			//prints all elements at index
			Node *tmp;
			tmp = hashTable->table[index];
			
			while(tmp->next!=NULL)
			{
				
				printf("%d:%d: ",index,tmp->key);
				printElement(hashTable,lookupData(hashTable,tmp->key));
				//printElement(hashTable,tmp);
				tmp=tmp->next;
			}
			printf("%d:%d: ",index,tmp->key);
			printElement(hashTable,lookupData(hashTable,tmp->key));
			//ptr=tmp->data;
			/*if(tmp->key==key)
			{
			}
			else
			{
				ptr=NULL;
			}
			return ptr;*/
			//ptr = hashTable->table[index]->data;
		}
	}
}
void *lookupData(HTable *hashTable, int key)
{
	int index;
	void *ptr;
	//N
	index = hashNode(hashTable->size,key);
	//printf("index is%d\n",index);
	//hashTable->table[index]==NULL
	if(!hashTable->table[index])
	{
		ptr = NULL;
		return ptr;
	}
	else
	{
		Node *tmp;
		tmp=( Node *)malloc(sizeof( Node));
		tmp = hashTable->table[index];
		while(tmp->next!=NULL&&tmp->key!=key)
		{
			tmp=tmp->next;
		}
		//ptr=tmp->data;
		if(tmp->key==key)
		{
			ptr=tmp->data;
		}
		else
		{
			ptr=NULL;
		}
		return ptr;
		//ptr = hashTable->table[index]->data;
	}
	//ptr = hashTable->table[index]->data;
	//printf("here\n");
	//printWord(ptr);
	//printf("here\n");
	
}

void destroyTable(HTable *hashTable)
{
	int i;
	int index;
	for(i=0;i<hashTable->size;i++)
	{
		index = i;
		if(hashTable->table[index]==NULL)
		{
			//printf("here\n");
		}
		else
		{
			Node *tmp;
			
			while(hashTable->table[index]!=NULL)
			{
				tmp = hashTable->table[index];
				if(tmp->next==NULL)
				{
					
					hashTable->destroyData(tmp->data);
					hashTable->table[index]=NULL;
				}
				else
				{
					
					hashTable->table[index]->data=tmp->next->data;
					hashTable->destroyData(tmp->data);
				}
			}
		}
	}
	free(hashTable);
}
void printNodeData(void *toBePrinted) 
{
	//printData(*((Node**)toBePrinted));
	//printf("%s\n",*((Node*)toBePrinted->data));
}
void printElement(HTable *hashTable,Node* toBePrinted)
{
	
	hashTable->printNode(toBePrinted);
}

void removeData(HTable *hashTable, int key)
{
	int index;
	index = hashNode(hashTable->size,key);
	Node *tmp;
	tmp=( Node *)malloc(sizeof( Node));
	tmp = hashTable->table[index];
	if(tmp->next==NULL)
	{
		
		hashTable->destroyData(tmp->data);
		hashTable->table[index]=NULL;
	}
	else
	{
		
		hashTable->table[index]=tmp->next;
		hashTable->destroyData(tmp->data);
	}
	//lookupData(hashTable,key);
	//hashTable->deleteFunction;
}