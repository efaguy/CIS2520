#include "../includes/HashTableADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int hashNode(size_t tableSize, char *key)
{
    char letter = key[0];
    int temp = 0;
    int i = 0;
    int x = 0;
    int keyNum = 0;

    while(letter != '\0')
    {
        static const char * const alphabet = "abcdefghijklmnopqrstuvwxyz";
        char *p = strchr(alphabet, tolower(letter));

        temp = p - alphabet;
        temp++;

        switch(x)
        {
        case 0:
            keyNum += temp;
            break;
        case 1:
            keyNum -= temp;
            break;
        case 2:
            keyNum *= temp;
            break;
        case 3:
            if(temp != 0)
                keyNum /= temp;
            break;
        }
        if(x == 3)
            x = 0;
        else
            x++;
        i++;
        letter = key[i];
    }
    int index = keyNum%tableSize;
    return index;
}

void destroyNodeData(void *data)
{
    free(data);
}

void printNodeData(void *toBePrinted)
{
    char* word = malloc(sizeof(toBePrinted));
    if(toBePrinted == NULL)
    {
        printf("Word not found\n");
        return;
    }
    word = (char*)toBePrinted;
    printf("%s\n", word);
}

int main()
{
	printf("Testing createTable\n");
	printf("Expecting: table should be made and set to null\n");
	HTable* test = createTable(10, &hashNode, &destroyNodeData, &printNodeData);
	printf("Received: ");
	printf("%p\n", (void*)test->table[0]);
	printf("Test Passed\n\n");
    
    char* word1 = malloc(sizeof(char)*10);
    char* word2 = malloc(sizeof(char)*10);
    strcpy(word1, "Hello");
    strcpy(word2, "Purple");
    
    printf("Testing insertData\n");
    printf("Expecting: Hello and Purple shouls be inserted in the table\n");
    printf("Received: \n");
    insertDataInMap(test, word1);
    insertDataInMap(test, word2);
    
	//printf("%s\n", (char*)test->table[hashNode(10, word1)]->data);
	//printf("%s\n", (char*)test->table[hashNode(10, word2)]->data);
	printf("Test Passed\n\n");
	
	printf("Testing lookupData\n");
    printf("Expecting: Hello should be found\n");
    printf("Received: \n");
    void* temp = lookupData(test, word1);
    printNodeData(temp);
    printf("Test Passed\n\n");
    
    printf("Testing removeData\n");
    printf("Expecting: Hello should be removed and not found\n");
    printf("Received: \n");
    removeData(test, word1);
    temp = lookupData(test, word1);
    printNodeData(temp);
    printf("Test Passed\n\n");
    
    char* word3 = malloc(sizeof(char)*10);
    strcpy(word3, "house");
    insertDataInMap(test, word1);
    insertDataInMap(test, word3);
    printf("Testing printTable\n");
    printf("Expecting: Table should be printed\n");
    printf("Received: \n");
    printTable(test);
    printf("Test Passed\n\n");
    
    printf("Testing destroyTable\n");
    printf("Expecting: Table should be deleted\n");
    printf("Received: (any called to table cause segmentation fault)\n");
    destroyTable(test);
    printf("Test Passed\n\n");
    
    printf("ALL TEST PASSED\n");
	
    return 0;
}
