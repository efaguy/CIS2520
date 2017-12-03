#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../includes/BinarySearchTreeAPI.h"
#include "../includes/rule.h"


int main(int args, char** argc)
{
	Tree* rules = createBinTree(&compareRule, &deleteRule, &printRule);
	
	Rule* rule1 = createRule("Happy", "I am Happy", 0.5,0.5,0.05, 5);
	Rule* rule2 = createRule("Weather", "It's raining", 0.9,0.5,0.05, 12);
	Rule* rule3 = createRule("Food", "Pie is my fav food", 0.6,0.512,0.05, 0);
	Rule* rule4 = createRule("Traffic", "There is no traffic", 0.5,0.21,0.05, 8);
	Rule* rule5 = createRule("Sad", "Don't be sad", 0.7,0.62,0.05, 0);
	
	printf("Rule 1:\n");
	printRule(rule1);
	printf("\nRule 2:\n");
	printRule(rule2);
	printf("\nRule 3:\n");
	printRule(rule3);
	printf("\nRule 4:\n");
	printRule(rule4);
	printf("\nRule 5:\n");
	printRule(rule5);
	printf("Testing addToTree\nExpected: all rules should added to tree\n");
	addToTree(rules, rule1);
	addToTree(rules, rule2);
	addToTree(rules, rule3);
	addToTree(rules, rule4);
	addToTree(rules, rule5);
	printf("Test passed\n\n");
	
	printf("\nTesting printInOrder\n");
	printInOrder(rules, printRule);
	printf("Test passed\n\n");
	
	printf("Testing removeFromTree\nExpected: Rule 5 shoud be removed\n");
	removeFromTree(rules, rule5);
	printf("Test passed\n\n");
	
	printf("Testing printPreOrder\n");
	printPreOrder(rules, printRule);
	printf("Test passed\n\n");
	
	printf("Testing printPostOrder\n");
	printPostOrder(rules, printRule);
	printf("Test passed\n");
	
	destroyBinTree(rules);
	return 0;
}
