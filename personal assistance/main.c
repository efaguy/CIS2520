#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <C:\Users\Eric\Desktop\New folder\personal assistance\BinarySearchTreeAPI.h>

int compareInt(const void* a, const void* b)
{
    int intA = (int*)a;
    int intB = (int*)b;

    //printf("A%d\nB%d\n",intA,intB);
    if(intA > intB)
    {
        return -1;
    }
    else if(intA < intB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void deleteInt(void* data)
{
    free(data);
}

void printInt(void* data)
{
    int toPrint = *(int*)data;
    printf("%d\n", toPrint);
}

int main()
{
    Tree* test = createBinTree(&compareInt, &deleteInt, &printInt);
    int one = 10;
    int two = 20;
    int three = 5;

    addToTree(test, (void*)one);
    addToTree(test, (void*)two);
    addToTree(test, (void*)three);

    printPreOrder(test, printInt);
    destroyBinTree(test);
    return 0;
}
