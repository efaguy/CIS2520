#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
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
	char temp[500];
	char *word;
	int choice = 0;
	int i = 0;
	int x = 0;
	char yn;
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
				response = malloc(sizeof(char)*500);
				if(fgets(keyword, 50, fp) != NULL)
				{
					removeNewLine(keyword);
					int len = strlen(keyword);
					if(keyword[len-1] == '.' || keyword[len-1] == '?' || keyword[len-1] == '!')
					{
						keyword[len-1] = '\0';
					}
					for(i = 0;i < len; i++)
					{
						keyword[i] = tolower(keyword[i]);
					}
					fgets(response, 500, fp);
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
				response = malloc(sizeof(char)*500);
				printf("Please enter the keyword: ");
				fgets(keyword, 50, stdin);
				removeNewLine(keyword);
				int len = strlen(keyword);
				if(keyword[len-1] == '.' || keyword[len-1] == '?' || keyword[len-1] == '!')
				{
					keyword[len-1] = '\0';
				}
				for(i = 0;i < len; i++)
				{
					keyword[i] = tolower(keyword[i]);
				}
				printf("Please enter the response: ");
				fgets(response, 500, stdin);
				removeNewLine(response);
				printf("Please enter the important of this rule: ");
				scanf("%lf", &rating);
				addToTree(rules, createRule(keyword, response, rating, rating, 0.05, 0));
				break;
			case 2:
				printf("What is the keyword for the rule you want to delete: ");
				fgets(temp, 50, stdin);
				removeNewLine(temp);
				Rule* toDelete = createRule(temp, "", 0, 0, 0, 0);
				removeFromTree(rules, toDelete);
				free(toDelete);
				break;
			case 3:
				printPreOrder(rules, printRule);
				break;
			case 4:
				printf("What is the keyword of the rule you wany to modify: ");
				fgets(temp, 50, stdin);
				removeNewLine(temp);
				len = strlen(temp);
				if(temp[len-1] == '.' || temp[len-1] == '!' || temp[len-1] == '!')
				{
					temp[len-1] = '\0';
				}
				for(i = 0;i < len; i++)
				{
					temp[i] = tolower(temp[i]);
				}
				Rule* search = createRule(temp, "", 0, 0, 0, 0);
				Rule* found = findInTree(rules, search);
				if(found != NULL)
				{
					printf("The current rating is %lf\n", getUserRate(found));
					printf("What would you like to set the rating to: ");
					scanf("%lf", &rating);
					getc(stdin);
					setRating(found, rating);
					printf("Rating changed\n");
				}
				else
				{
					printf("No rule found with that keyword\n");
				}
				free(search);
				break;
			case 5:;
				Rule** words;
				words = malloc(sizeof(Rule*));
				printf("Please enter a question?\n");
				fgets(temp, 500, stdin);
				removeNewLine(temp);
				len = strlen(temp);
				if(temp[len-1] == '.' || temp[len-1] == '?' || temp[len-1] == '!')
				{
					temp[len-1] = '\0';
				}
				for(i = 0;i < len; i++)
				{
					temp[i] = tolower(temp[i]);
				}
				i = 0;
				word = strtok(temp, " ");
				while(true)
				{
					words = realloc(words, (sizeof(Rule*)*(i+1)));
					Rule* search = createRule(word, "", 0, 0, 0, 0);
					words[i]  = findInTree(rules, search);
					if(words[i] != NULL)
					{
						i++;
					}
					word = strtok(NULL, " ");
					if(word == NULL)
					{
						break;
					}
				}
				if(i == 0)
				{
					printf("I'm sorry I can't help you with that(yet)\n");
					break;
				}
				Rule* largest = words[0];
				for(x = 0;x < i;x++)
				{
					if((getUserRate(words[x]) + getSysRate(words[x])) > (getUserRate(largest) + getSysRate(largest)))
					{
						largest = words[x];
					} 
				}
				printf("%s\n", getResponse(largest)); 
				printf("Was this feedback helpful \'y\' or \'n\'\n");
				scanf("%c", &yn);
				fgetc(stdin);
				updateRating(largest, yn);
				break;
			case 9:
				return 0;
				
				
		}
	}
	printPreOrder(rules, printRule);
	destroyBinTree(rules);
    return 0;
}
