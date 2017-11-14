
#include "HashTableADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int hashNode(size_t tableSize, int key)
{
    int index = key%tableSize;
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
        printf("Invalid Data\n");
    }
    word = (char*)toBePrinted;
    printf("%s\n", word);
}

int main()
{
    HTable* test = createTable(10, &hashNode, &destroyNodeData, &printNodeData);
    char* word1 = malloc(sizeof(char)*10);
    char* word2 = malloc(sizeof(char)*10);
    strcpy(word1, "Hello");
    strcpy(word2, "Purple");
    insertDataInMap(test, word1);
    insertDataInMap(test, word2);
    void* temp = lookupData(test, produceKey(word1));
    printNodeData(temp);
    temp = lookupData(test, produceKey(word2));
    printNodeData(temp);
    removeData(test, produceKey(word1));
    temp = lookupData(test, produceKey(word1));
    printNodeData(temp);
    temp = lookupData(test, produceKey(word2));
    printNodeData(temp);
    insertDataInMap(test,word1);
    temp = lookupData(test, produceKey(word1));
    printNodeData(temp);
    temp = lookupData(test, produceKey(word2));
    printNodeData(temp);
    destroyTable(test);
    return 0;
}
