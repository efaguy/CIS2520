#include "../includes/HashTableADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
*@return pointer to the hash table
*@param size size of the hash table
*@param hashFunction function pointer to a function to hash the data
*@param destroyData function pointer to a function to delete a single piece of data from the hash table
*@param printNode function pointer to a function that prints out a data element of the table
**/
HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, char* key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted))
{
    HTable* tmpTable = malloc(sizeof(HTable));
        tmpTable->size = size;
        tmpTable->table = malloc(sizeof(Node*)*tmpTable->size);
        int i = 0;
        for(i = 0;i < size;i++)
        {
            tmpTable->table[i] = NULL;
        }

        tmpTable->hashFunction = hashFunction;
        tmpTable->destroyData = destroyData;
        tmpTable->printNode = printNode;
        tmpTable->add = &insertDataInMap;
        return tmpTable;

}
/**Function for creating a node for the hash table.
*@pre Node must be cast to void pointer before being added.
*@post Node is valid and able to be added to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data is a generic pointer to any data type.
*@return returns a node for the hash table
**/
Node *createNode(char* key, void *data)
{
    Node* tmpNode = malloc(sizeof(Node));
    tmpNode->data = data;
    tmpNode->key = key;
    tmpNode->next = NULL;
    return tmpNode;
}

/** Deletes the entire hash table and frees memory of every element.
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
**/
void destroyTable(HTable *hashTable)
{
    int i = 0;
    Node* curNode = hashTable->table[0];
	while(curNode != NULL)
	{
	    Node* nextNode = curNode->next;
	    while(nextNode != NULL)
        {
            hashTable->destroyData(nextNode->data);
            free(nextNode);
            nextNode = nextNode->next;
        }
        hashTable->destroyData(curNode->data);
        free(curNode);
        i++;
        curNode = hashTable->table[i];
	}
	free(hashTable);
}

/**Inserts a Node in the hash table.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data pointer to generic data that is to be inserted into the list
**/
void insertData(HTable *hashTable, char* key, void *data)
{
    int index = hashTable->hashFunction(hashTable->size, key);
    Node* newNode = createNode(key, data);
    Node* curNode = hashTable->table[index];
    if(hashTable->table[index] == NULL)
    {
        hashTable->table[index] = newNode;
        printf("Successfully added %s\n", (char*)data);
        return;
    }
    while(curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    curNode->next = newNode;
    printf("Successfully added %s\n", (char*)data);
}
/** THIS FUNCTION IS NOT MANDATORY, users call this function to insert a Node in the hash table.
* It's meant as a wrapper for insertData so the users don't need to generate the key when adding.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param data pointer to generic data that is to be inserted into the list
**/
void insertDataInMap(HTable *hashTable, void *data)
{
	int i = 0;
	char *temp = data;
    for(i = 0; i < strlen(temp); i++)
    {
        temp[i] = tolower(temp[i]);
    }
    i = 0;
    Node* curNode = hashTable->table[0];
	while(true)
	{
        if(curNode != NULL)
        {
            if(strcmp(curNode->key, temp) == 0)
            {
                printf("%s is already in the dictionary\n", temp);
                return;
            }
            while(curNode->next != NULL)
            {
                curNode = curNode->next;
                if(strcmp(curNode->key, temp) == 0)
                {
                    printf("%s is already in the dictionary\n", temp);
                    return;
                }
            }
        }
        i++;
        if(i == hashTable->size)
        {
            break;
        }
        curNode = hashTable->table[i];
	}
    char* key;
    key = data;
    i = 0;
    for(i = 0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }
    insertData(hashTable, key, data);
}

/**Function to remove a node from the hash table
 *@pre Hash table must exist and have memory allocated to it
 *@post Node at key will be removed from the hash table if it exists.
 *@param hashTable pointer to the hash table struct
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 **/
void removeData(HTable *hashTable, char* key)
{
    char* empty = malloc(sizeof(char)*2);
    strcpy(empty, "#");
    int i = -1;
    Node* curNode = hashTable->table[0];
	while(true)
	{
	    i++;
        if(i == hashTable->size)
        {
            printf("%s could not be found in dictionary\n", key);
            return;
        }
        curNode = hashTable->table[i];
        if(curNode != NULL)
        {
            if(strcmp(curNode->key, key) == 0)
            {
                printf("Successfully deleted %s\n", curNode->key);
                curNode->data = (void*)empty;
                curNode->key = (void*)empty;
                return;
            }
            while(curNode->next != NULL)
            {
                curNode = curNode->next;
                if(strcmp(curNode->key, key) == 0)
                {
                    printf("Successfully deleted %s\n", curNode->key);
                    curNode->data = (void*)empty;
                    curNode->key = (void*)empty;
                    return;
                }
            }
        }
	}
}

/**Function to return the data from the key given.
 *@pre The hash table exists and has memory allocated to it
 *@param hashTable pointer to the hash table containing data nodes
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 *@return returns a pointer to the data in the hash table. Returns NULL if no match is found.
 **/
void *lookupData(HTable *hashTable, char* key)
{
    int i = 0;
    for(i = 0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }
    i = 0;
    Node* curNode = hashTable->table[0];
	while(true)
	{
        if(curNode != NULL)
        {
            if(strcmp(curNode->key, key) == 0)
            {
                return curNode->data;
            }
            while(curNode->next != NULL)
            {
                curNode = curNode->next;
                if(strcmp(curNode->key, key) == 0)
                {
                    return curNode->data;
                }
            }
        }
        i++;
        if(i == hashTable->size)
        {
            break;
        }
        curNode = hashTable->table[i];
	}
	return NULL;
}

/**Function to print out the hash table.
 *@pre The hash table exists and has memory allocated to it
 *@param hashTable pointer to the hash table containing data nodes
 **/
void printTable(HTable *table)
{
    int x;
    char* key;
    Node* curNode = table->table[0];
    Node* nextNode = NULL;
    for(x = 0;x < table->size; x++)
	{
	    curNode = table->table[x];
	    if(curNode != NULL)
        {
            nextNode = curNode->next;
        }
	    while(nextNode != NULL)
        {
			if(strcmp((char*)nextNode->data,"#") != 0)
            {
				key = (char*)nextNode->data;
				printf("%d:%s:", x, key);
				table->printNode(nextNode->data);
			}
            nextNode = nextNode->next;
        }
        if(curNode != NULL)
        {
            if(strcmp((char*)curNode->data,"#") != 0)
            {
                key = (char*)curNode->data;
                printf("%d:%s:", x, key);
                table->printNode(curNode->data);
            }
        }
	}
}



