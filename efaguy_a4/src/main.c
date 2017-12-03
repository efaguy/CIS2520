#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/BinarySearchTreeAPI.h"
#include "../includes/rule.h"

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
	FILE * fp = NULL;
	double rating;
	char* keyword;
	char* response;
	char delete[50];
	int choice = 0;
    Tree* rules = createBinTree(&compareRule, &deleteRule, &printRule);
    
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
				keyword = malloc(sizeof(char)*50);
				response = malloc(sizeof(char)*100);
				if(fgets(keyword, 50, fp) != NULL)
				{
					removeNewLine(keyword);
					fgets(response, 100, fp);
					removeNewLine(response);
					addToTree(rules, createRule(keyword, response, 0.5, 0.5,0.05, 0));
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
	while(true)
	{
		printf("Please select on of the following options: \n");
		printf("1) Add a new rule \n2) Remove a rule \n3) Display rules \n4) Modify rule rating \n5) Dicuss \n\n9) Quit \n");
		scanf("%d", &choice);
		getc(stdin);
		switch(choice)
		{
			case 1:
				keyword = malloc(sizeof(char)*50);
				response = malloc(sizeof(char)*100);
				printf("Please enter the keyword: ");
				fgets(keyword, 50, stdin);
				removeNewLine(keyword);
				printf("Please enter the respone: ");
				fgets(response, 100, stdin);
				removeNewLine(response);
				printf("Please enter the important of this rule: ");
				scanf("%lf", &rating);
				addToTree(rules, createRule(keyword, response, rating, rating, 0.05, 0));
				break;
			case 2:
				printf("What is the keyword for the rule you want to delete: ");
				fgets(delete, 50, stdin);
				removeNewLine(delete);
				printf("%s\n", delete);
				Rule* toDelete = createRule(delete, "", 0, 0, 0, 0);
				removeFromTree(rules, toDelete);
				free(toDelete);
				break;
			case 3:
				printPreOrder(rules, printRule);
				break;
			case 9:
				return 0;
				
				
		}
	}
	printPreOrder(rules, printRule);
	destroyBinTree(rules);
    return 0;
}
