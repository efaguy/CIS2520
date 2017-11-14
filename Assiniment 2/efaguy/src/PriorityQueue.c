
#include <stdio.h>
#include <stdlib.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/PriorityQueue.h"
#include "../includes/patient.h"

/**Function to create a queue
 *@return pointer to the queue
**/
Queue *createQueue(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
	Queue* q = malloc(sizeof(Queue));
	q->list = initializeList(printFunction, deleteFunction, compareFunction);
	return q;
}
/**Inserts a Node to the back of the queue.
*@pre 'Queue' type must exist and be used in order to keep track of the linked list.
*@param q a pointer to the queue
*@param toBeAdded a pointer to data that is to be added to the queue
**/
void insert(Queue *q, void* data, int priorityValue)
{
	insertBack(q->list, data, priorityValue);
	q->count++;
}

/**Inserts a Node to the queue based on its priority value.
*@pre 'Queue' type must exist and be used in order to keep track of the linked list.
*@param q a pointer to the queue
*@param toBeAdded a pointer to data that is to be added to the queue
**/
void pInsert(Queue* q, void *toBeAdded, int priorityValue)
{
	q->count++;
	Node* n = initializeNode(toBeAdded, priorityValue);
	Node* curN = q->list->head;
	if(curN == NULL)
	{
		q->list->head = n;
		q->list->tail = n;
		n->next = NULL;;
		n->previous = NULL;
		return;
	}
	if(n->priorityValue < curN->priorityValue)
	{
		insertFront(q->list, toBeAdded, priorityValue);
		return;
	}
	if(n->priorityValue > q->list->tail->priorityValue)
	{
		insertBack(q->list, toBeAdded, priorityValue);
		return;
	} 
	while(curN != NULL)
	{
		if(curN->next ==  NULL)
		{
			insertBack(q->list, toBeAdded, priorityValue);
			return;
		}
		if(n->priorityValue >= curN->priorityValue && n->priorityValue < curN->next->priorityValue)
		{
			n->next = curN->next;
			n->previous = curN;
			if(curN->next == NULL)
			{
				q->list->tail = n;
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
/** Deletes the entire queue, starting with the nodes, followed by the queue itself.
*@pre 'queue' type must exist and be used in order to keep track of the linked list.
*@param q pointer to the queue
**/
void destroy(Queue *q)
{
	deleteList(q->list);
	free(q);
}

/** Returns the front of the queue and then removes it from the list
 * @param q pointer the the queue
 **/
void* pop(Queue *q)
{
	if(q)
	{
		void* data = peek(q);
		int pass = deleteNodeFromList(q->list, data);
		if(pass == 1)
		{
			q->count--;
		}
		return data;
	}
	return NULL;
}

/** Returns the front of the queue
 * @param q pointer the the queue
 **/
void* peek(Queue *q)
{
	return getFromFront(q->list);
}
/** Returns 0 if the list is empty, 1 otherwise
 * @param q pointer the the queue
 **/
int isEmpty(Queue *q)
{
	if(q->count == 0)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}
