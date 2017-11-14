#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/car.h"

/**Function to point the list head to the appropriate functions. Allocates memory to the struct.
*@return pointer to the list head
**/
List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
	List* l = malloc(sizeof(List));
	l->head = NULL;
	l->tail = NULL;
	l->printFunction = printFunction;
	l->deleteFunction = deleteFunction;
	l->compareFunction = compareFunction;
	return l;
}

/**Function for creating a node for a linked list. This node contains generic data and may be connected to 
other notes in a list.
*@pre data should be of same size of void pointer on the users machine to avoid size conflicts. data must be valid.
*data must be cast to void pointer before being added.
*@post data is valid to be added to a linked list
*@return On success returns a node that can be added to a linked list. On failure, returns NULL.
*@param data - is a generic pointer to any data type.
**/
Node *initializeNode(void *data)
{
	Node* n = malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	n->previous = NULL;
	return n;
}

/**Inserts a Node to the front of a linked list. The list then updates accordingly to adhere to the ADT.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the dummy head of the list
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertFront(List *list, void *toBeAdded)
{
	Node* n = initializeNode(toBeAdded);
	if(list->head == NULL)
	{
		list->head = n;
		list->tail = n;
		n->next = NULL;;
		n->previous = NULL;
		return;
	}
	else
	{
		list->head->previous = n;
		n->next = list->head;
		list->head = n;
	}
}

/**Inserts a Node to the back of a linked list. The list then updates accordingly to adhere to the ADT.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the dummy head of the list
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertBack(List *list, void *toBeAdded)
{
	Node* n = initializeNode(toBeAdded);
	if(list->head == NULL)
	{
		list->head = n;
		list->tail = n;
		n->next = NULL;;
		n->previous = NULL;
		return;
	}
	else
	{
		list->tail->next = n;
		n->previous = list->tail;
		list->tail = n;
		n->next = NULL;
	}
}
/** Deletes the entire linked list head to tail, starting with the nodes, followed by the list itself.
*@pre 'List' type must exist and be used in order to keep track of the linked list.
*@param list pointer to the List-type dummy node
**/
void deleteList(List *list)
{
	Node* n = list->head;
	while(n != NULL)
	{
		list->deleteFunction(n->data);
		free(n);
		n = n->next;
	}
	free(list);
}

/** Uses the comparison function in the List struct to place the element in the appropriate position in the list.
*this is intended to be used from the beginning in order to keep the list completely sorted.
*@pre List exists and has memory allocated to it. Node to be added is valid.
*@post The node to be added will be placed immediately before or after the first occurrence of a related node
*@param list a pointer to the dummy head of the list containing function pointers for delete and compare, as well 
as a pointer to the first and last element of the list.
*@param toBeAdded a pointer to data that is to be added to the linked list
**/
void insertSorted(List *list, void *toBeAdded)
{
	Node* n = initializeNode(toBeAdded);
	Node* curN = list->head;
	if(curN == NULL)
	{
		list->head = n;
		list->tail = n;
		n->next = NULL;;
		n->previous = NULL;
		return;
	}
	if(list->compareFunction(toBeAdded, curN->data) <= 0)
	{
		insertFront(list, toBeAdded);
		return;
	}
	if(list->compareFunction(toBeAdded, list->tail->data) >= 0)
	{
		insertBack(list, toBeAdded);
		return;
	} 
	while(curN != NULL)
	{
		if(curN->next ==  NULL)
		{
			insertBack(list, toBeAdded);
			return;
		}
		if(list->compareFunction(toBeAdded, curN->data) > 0 && list->compareFunction(toBeAdded, curN->next->data) <= 0)
		{
			n->next = curN->next;
			n->previous = curN;
			if(curN->next == NULL)
			{
				list->tail = n;
			}
			else
			{
				curN->next->previous = n;
			}
			curN->next = n;
			return;
		}
		curN = curN->next;
	}
}

/**Function to remove a node from the list and alter the pointers accordingly to not disrupt the order of the 
 *data structure. 
 *@pre List must exist and have memory allocated to it
 *@post toBeDeleted will have its memory freed if it exists in the list.
 *@param list pointer to the dummy head of the list containing deleteFunction function pointer
 *@param toBeDeleted pointer to data that is to be removed from the list
 *@return returns EXIT_SUCCESS on success, and EXIT_FAILURE when empty. Returns -1 when the node cannot be found.
 **/
int deleteNodeFromList(List *list, void *toBeDeleted)
{
	Node* n = list->head;
	while(n != NULL)
	{
		if(n->data == toBeDeleted)
		{
			//printCar(n->data);
			if(n->previous != NULL)
			{
				n->previous->next = n->next;
			} 
			else
			{
				list->head = n->next;
			}
			if(n->next != NULL)
			{
				n->next->previous = n->previous;
			}
			else
			{
				list->tail = n->previous;
			}
			list->deleteFunction(n->data);
			free(n);
			return 1;
		}
		n = n->next;
	}
	return -1;
}

/**Function to return the data at the front of the list.
 *@pre The list exists and has memory allocated to it
 *@param list pointer to the dummy head of the list containing the head of the list
 *@return pointer to the data located at the head of the list
 **/
void *getFromFront(List *list)
{
	return list->head->data;
}

/**Function to return the data at the back of the list.
 *@pre The list exists and has memory allocated to it
 *@param list pointer to the dummy head of the list containing the tail of the list
 *@return pointer to the data located at the tail of the list
 **/
void *getFromBack(List *list)
{
	return list->tail->data;
}

/**Function to print list from head to tail. This will utilize the list's printNode function pointer to print.
 *@pre List must exist, but does not have to have elements.
 *@param list Pointer to linked list dummy head.
 **/
void printForward(List *list)
{
	Node* n = list->head;
	while(n != NULL)
	{
		list->printFunction(n->data);
		n = n->next;
	}
}

/**Function to print list from tail to head. This will utilize the list's printNode function pointer to print.
 *@pre List must exist, but does not have to have elements.
 *@param list Pointer to linked list dummy head.
 **/
void printBackwards(List *list)
{
	Node* n = list->tail;
	while(n != NULL)
	{
		list->printFunction(n->data);
		n = n->previous;
	}
}
