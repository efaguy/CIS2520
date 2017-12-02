#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/BinarySearchTreeAPI.h"
#include "../includes/rule.h"

int main()
{
    Tree* test = createBinTree(&compareRule, &deleteRule, &printRule);
	Rule* one = createRule("c", "It's sunny", 0.5, 0.5, 0.05, 0);
	Rule* two = createRule("b", "I hate life", 1, 0.7, 0.05, 5);
	Rule* three = createRule("a", "daf", 0.2,0.8,0.001, 12);

    addToTree(test, (void*)one);
    addToTree(test, (void*)two);
    addToTree(test, (void*)three);

   /* printf("Printing preOrder:\n\n");
    printPreOrder(test, printInt);

    printf("Printing postOrder:\n\n");
    printPostOrder(test, printInt);

    printf("Printing inOrder:\n\n");
    printInOrder(test, printInt);
*/
    //removeFromTree(test, (void*)two);

    printf("Printing InOrder:\n\n");
    printInOrder(test, printRule);
    destroyBinTree(test);
    return 0;
}
