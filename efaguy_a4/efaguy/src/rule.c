#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/rule.h"


Rule* createRule(char* keyword, char* response, double userRate, double sysRate, double learnRate, int uses)
{
	Rule* r = malloc(sizeof(Rule));
	r->keyword = keyword;
	r->response = response;
	r->userRate = userRate;
	r->sysRate = sysRate;
	r->learnRate = learnRate;
	r->uses = uses;
	return r;
}
char* getKeyword(Rule* rule)
{
	return rule->keyword;
}

char* getResponse(Rule* rule)
{
	return rule->response;
}

double getUserRate(Rule* rule)
{
	return rule->userRate;
}

double getSysRate(Rule* rule)
{
	return rule->sysRate;
}

double getLearnRate(Rule* rule)
{
	return rule->learnRate;
}

int getUses(Rule* rule)
{
	return rule->uses;
}

void setRating(Rule* rule, double rating)
{
	rule->userRate = rating;
}

void updateRating(Rule* rule, char way)
{
	rule->uses++;
	double update = rule->sysRate * (rule->learnRate/rule->uses);
	printf("%lf\n", update);
	if(way == 'y')
	{
		rule->sysRate = rule->sysRate + update;
	}
	else
	{
		rule->sysRate = rule->sysRate - update;
	}
}

int compareRule(const void* a, const void* b)
{
	Rule* rule1 = (Rule*)a;
	Rule* rule2 = (Rule*)b;
	
	if(strcmp(rule1->keyword, rule2->keyword) > 0)
	{
		return 1;
	}
	else if(strcmp(rule1->keyword, rule2->keyword) < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
	
}

void deleteRule(void* data)
{
	Rule* r = (Rule*)data;
	char* word = r->keyword;
	char* resp = r->response;
	free(word);
	free(resp);
	free(r);
}

void printRule(void* data)
{
	Rule* r = (Rule*)data;
	printf("%s\tRating:%.2f\tSystem:%.2f\tOccurrences:%d\n",r->keyword,r->userRate,r->sysRate,r->uses);
}
