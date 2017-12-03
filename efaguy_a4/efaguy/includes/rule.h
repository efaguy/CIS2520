#ifndef RULE_H_INCLUDED
#define RULE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

typedef struct termRule {
    char* keyword;
	char* response;
	double userRate;
	double sysRate;
	double learnRate;
	int uses;
} Rule;


Rule* createRule(char* keyword, char* response, double userRate, double sysRate, double learnRate, int uses);
 
char* getKeyword(Rule* rule);

char* getResponse(Rule* rule);

double getUserRate(Rule* rule);

double getSysRate(Rule* rule);

double getLearnRate(Rule* rule);

int getUses(Rule* rule);

void setRating(Rule* rule, double rating);

void updateRating(Rule* rule, char way);

int compareRule(const void* a, const void* b);

void deleteRule(void* data);

void printRule(void* data);

#endif
