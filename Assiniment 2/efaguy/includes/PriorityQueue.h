#ifndef _QUEUE_API_
#define _QUEUE_API_

#include <stdio.h>
#include <stdlib.h>
#include "../includes/LinkedListAPI.h"

typedef struct queue {
	List* list;
	int count;
} Queue;

/**Function to create a queue
 *@return pointer to the queue
**/
Queue *createQueue(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

/**Inserts a Node to the queue.
*@pre 'Queue' type must exist and be used in order to keep track of the linked list.
*@param q a pointer to the queue
*@param toBeAdded a pointer to data that is to be added to the queue
**/
void insert(Queue *q, void* data, int priorityValue);

/**Inserts a Node to the queue based on its priority value.
*@pre 'Queue' type must exist and be used in order to keep track of the linked list.
*@param q a pointer to the queue
*@param toBeAdded a pointer to data that is to be added to the queue
**/
void pInsert(Queue* q, void *toBeAdded, int priorityValue);


/** Deletes the entire queue, starting with the nodes, followed by the queue itself.
*@pre 'queue' type must exist and be used in order to keep track of the linked list.
*@param q pointer to the queue
**/
void destroy(Queue *q);

/** Returns the front of the queue and then removes it from the list
 * @param q pointer the the queue
 **/
void* pop(Queue *q);

/** Returns the front of the queue
 * @param q pointer the the queue
 **/
void* peek(Queue *q);

/** Returns 0 if the list is empty, 1 otherwise
 * @param q pointer the the queue
 **/
int isEmpty(Queue *q);



#endif
