#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../includes/BinarySearchTreeAPI.h"
#include "../includes/rule.h"
/**************************************
Interface for a Binary Tree ADT
Author:  Judi McCuaig
October, 2012
Modfied: James Fraser (Nov 2017)
**************************************/

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node.
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data)
{
    TreeNode* newNode = malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del, PrintFunc print)
{
    Tree* newTree = malloc(sizeof(Tree));
    newTree->compareFunc = compare;
    newTree->deleteFunc = del;
    newTree->printFunc = print;
    newTree->root = NULL;
    return newTree;
}

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void destroyBinTree(Tree * toDestroy)
{
    destroy(toDestroy->root, toDestroy->deleteFunc);
    free(toDestroy);
}

/**
 * Add data to a tree
 * @param theTree
 * @param data
 */
void addToTree(Tree * theTree, TreeDataPtr data)
{
    TreeNode* newNode = createTreeNode(data);
    TreeNode* curNode = theTree->root;
    TreeNode* prev = NULL;
    if(theTree->root == NULL)
    {
        printf("ROOT: ");
        printRule(newNode->data);
        newNode->parent = NULL;
        theTree->root = newNode;
        return;
    }
    while(true)
    {
       // printf("tue");
        if(curNode == NULL)
        {
            printf("placed: ");
            printRule(newNode->data);
            printf("Parent: ");
            printRule(prev->data);
            if(theTree->compareFunc(prev->data,data) == 1)
            {
                prev->right = newNode;
            }
            else
            {
                prev->left = newNode;
            }
            newNode->parent = prev;
            curNode = newNode;
            return;
        }
        else if(theTree->compareFunc(curNode->data,data) == 1)
        {
            //printf("right: ");
            //printRule(data);
            prev = curNode;
            curNode = curNode->right;
        }
        else
        {
            //printf("left: ");
            //printRule(data);
            prev = curNode;
            curNode = curNode->left;
        }
    }

}

/**
 * Remove data from the tree
 * @param theTree
 * @param data
 */
void removeFromTree(Tree * theTree, TreeDataPtr data)
{
    TreeNode* curNode = theTree->root;
    printf("Looking for : \n");
    printRule(data);
    while(true)
    {
        if(curNode == NULL)
        {
			printf("????\n");
            return;
        }
        else if(theTree->compareFunc(curNode->data,data) == 0)
        {
            break;
        }
        else if(theTree->compareFunc(curNode->data,data) == 1)
        {
            curNode = curNode->right;
        }
        else if(theTree->compareFunc(curNode->data,data) == -1)
        {
            curNode = curNode->left;
        }
    }
    printRule(curNode->data);
    if(isLeaf(curNode))
    {
		if(curNode->parent->left != NULL)
		{
			if(strcmp(curNode->data, curNode->parent->left->data) == 0)
			{
				curNode->parent->left = NULL;
			}
		}
		else if(curNode->parent->right != NULL)
		{
			if(strcmp(curNode->data, curNode->parent->right->data) == 0)
			{
				curNode->parent->right = NULL;
			}
		}
		free(curNode);
        return;
    }
    else if(!hasTwoChildren(curNode))
    {
        TreeNode* temp = NULL;
        if(curNode->right == NULL)
        {
            temp = curNode->left;
        }
        else
        {
            temp = curNode->right;
        }
		if(curNode->parent->left != NULL)
		{
			if(strcmp(curNode->data, curNode->parent->left->data) == 0)
			{
				curNode->parent->left = temp;
			}
		}
		if(curNode->parent->right != NULL)
		{
			if(strcmp(curNode->data, curNode->parent->right->data) == 0)
			{
				curNode->parent->right = temp;
			}
		}
		theTree->deleteFunc(curNode->data);
		free(curNode);
		return;
    }
    else if(hasTwoChildren(curNode))
    {
        printf("two\n");
        TreeNode* node = curNode;
        TreeNode* small = curNode->left;
        while(true)
        {
            if(node == NULL)
            {
                break;
            }
            if(theTree->compareFunc(node->data, small->data) == -1)
            {
                small = node;
            }
            node = node->right;
        }
        printRule(small->data);
        if(curNode->parent == NULL)
        {
			small->left = theTree->root->left;
			small->right = theTree->root->right;
			theTree->root = small;
		}
        else if(curNode->parent->left != NULL)
		{
			printf("left del\n");
			printRule(curNode->data);
			printRule(curNode->parent->right->data);
			if(strcmp(curNode->data, curNode->parent->right->data) == 0)
			{
				printf("left del\n");
				curNode->parent->right = small;
			}
		}
		else if(curNode->parent->right != NULL)
		{
			printf("right del\n");
			if(strcmp(curNode->data, curNode->parent->right->data) == 0)
			{
				printf("right del\n");
				curNode->parent->right = small;
			}
		}
		theTree->deleteFunc(curNode->data);
		free(curNode);
        return;
    }
}


/**
 * This function searches the tree for the target data
 * @param  theTree
 * @param  data
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data )
{
    TreeNode* curNode = theTree->root;
    while(true)
    {
        if(curNode == NULL)
        {
            return NULL;
        }
        else if(theTree->compareFunc(curNode->data,data) == 0)
        {
            return curNode->data;
        }
        else if(theTree->compareFunc(curNode->data,data) == 1)
        {
            curNode = curNode->right;
        }
        else if(theTree->compareFunc(curNode->data,data) == -1)
        {
            curNode = curNode->left;
        }
    }
}

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree)
{
    return theTree->root;
}

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData)
{
    inOrder(theTree->root, printData);
}

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData)
{
    preOrder(theTree->root, printData);
}

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData)
{
    postOrder(theTree->root, printData);
}

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTee)
{
    if(theTee->root == NULL)
    {
        return 1;
    }
    return 0;
}


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode)
{
    if(treeNode->left == NULL && treeNode->right == NULL)
    {
        return 1;
    }
    return 0;
}

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode)
{
    if(treeNode->left != NULL && treeNode->right != NULL)
    {
        return 1;
    }
    return 0;
}

/**
 * Helper funciton Get the height of a particulat Node in the tree.
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree.
 */
int getHeight( TreeNode* treeNode )
{
    if(treeNode == NULL)
    {
        return 0;
    }
    int left = getHeight(treeNode->left);
    int right = getHeight(treeNode->right);
    if(left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
    return 0;
}


/**
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 */

void destroy(TreeNode* node, DeleteFunc del)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        destroy(node->left, del);
        //printf("left");
        destroy(node->right, del);
        //printf("right");
        del(node->data);
        //printf("free");
        free(node);
    }
}

void inOrder(TreeNode* node, PrintFunc print)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        inOrder(node->left, print);
        print(node->data);
        inOrder(node->right, print);
    }
}

void preOrder(TreeNode* node, PrintFunc print)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        print(node->data);
        preOrder(node->left, print);
		preOrder(node->right, print);
    }
}

void postOrder(TreeNode* node, PrintFunc print)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        preOrder(node->left, print);
        preOrder(node->right, print);
        print(node);
    }
}

void remover(TreeNode* node, DeleteFunc del)
{

}
