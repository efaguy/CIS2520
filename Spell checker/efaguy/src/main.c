#include "../includes/HashTableADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//Function to hash a string
int hashNode(size_t tableSize, char *key)
{
    char letter = key[0];
    int temp = 0;
    int i = 0;
    int x = 0;
    int keyNum = 0;
    //Convert the word to a number letter by letter
    while(letter != '\0')
    {
        static const char * const alphabet = "abcdefghijklmnopqrstuvwxyz";
        char *p = strchr(alphabet, tolower(letter));

        temp = p - alphabet;
        temp++;

        //Depending in the position of the letter perform a operation on the key
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
    //Modulo by the table size
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

//To remove the newline from the end of string when using fgets
void removeNewLine(char* word)
{
    int len = strlen(word);
    if(word[len-1] == '\n')
    {
        word[len-1] = '\0';
    }
}

int main(int args, char** argc)
{
    HTable* dictionary = createTable(100, &hashNode, &destroyNodeData, &printNodeData);
    FILE* fp = NULL;
    int choice;
    char* temp;
    char filename[10];
    int right = 0;
    int wrong = 0;
    if(args > 1)
    {
		fp = fopen(argc[1], "r");
		if(fp == NULL)
		{
			printf("Error reading from file\n");
		}
		else
		{
			//Read in from file
			while(true)
			{
				char* word = malloc(sizeof(char)*50);
				if(fgets(word, 50, fp) != NULL)
				{
					removeNewLine(word);
					insertDataInMap(dictionary, word);
				}
				else
				{
					fclose(fp);
					break;
				}
			}
		}
	}
	else
	{
		printf("Error reading from file\n");
	}
    //Main command loop
    do
    {
        printf("Please select one of the following options:\n");
        printf("1) Add a word to the Dictionary\n2) Remove a word from Dictionary\n3) Spell Check a file\n4) Show Dictionary Words\n5) Quit\n");
        scanf("%d", &choice);
        getc(stdin);
        //printf()
        switch(choice)
        {
        //Adding a word
        case 1:
            printf("\nWhat word would you like to add: ");
            temp = malloc(sizeof(char)*50);
            fgets(temp, 50, stdin);
            removeNewLine(temp);
            insertDataInMap(dictionary, (void*)temp);
            printf("\n");
            break;
        //Removing a word
        case 2:
            printf("\nWhat word would you like to remove: ");
            temp = malloc(sizeof(char)*50);
            fgets(temp, 50, stdin);
            removeNewLine(temp);
            removeData(dictionary, temp);
            printf("\n");
            break;
        //Spell check a word
        case 3:
            right = 0;
            wrong = 0;
            printf("What file would you like to spell check: ");
            fgets(filename, 50, stdin);
            removeNewLine(filename);
            fp = fopen(filename, "r");
            if(fp  == NULL)
            {
				printf("Error reading from file\n");
                break;
            }
            char word[50];
            printf("\nFile processed by Spell Check %s:\n", filename);
            //Read in from file and check if the word in the table
            while(true)
            {
                if(fgets(word, 50, fp) != NULL)
                {
                    removeNewLine(word);
                    if(lookupData(dictionary, (char*)word) == NULL)
                    {
                        wrong++;
                        printf("%s was not found in dictionary\n", word);
                    }
                    else
                    {
                        right++;
                    }
                }
                else
                {
                    printf("Summary:\n");
                    printf("Correctly spelt words: %d\n", right);
                    printf("Incorrectly spelt words: %d\n\n", wrong);
                    break;
                }
            }
            break;
        //Printing out the dictionary
        case 4:
            printf("\n");
            printTable(dictionary);
            printf("\n");
            break;
        case 5:
            break;
        default:
            printf("Please enter a valid choice\n");
        }
    } while(choice != 5);
    destroyTable(dictionary);

    return 0;
}
