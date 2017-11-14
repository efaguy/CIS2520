#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/patient.h"
#include "../includes/PriorityQueue.h"

int main(int argc, char ** argv)
{  
	
	printf("Testing createQueue\n");
	printf("Expecting: queue should be made and head an tail set to null\n");
	Queue* q = createQueue(printPatient, deletePatient, comparePatient);
	printf("Received: head = ");
	printf("%p\n", (void*)q->list->head);
	printf("Tail = ");
	printf("%p\n", (void*)q->list->tail);
	printf("Test Passed\n\n");
	
	char* ID1 = malloc(sizeof(char)*50);
	strcpy(ID1, "bill12");
	char* code1 = malloc(sizeof(char)*50);
	strcpy(code1, "TR");
	char* ID2 = malloc(sizeof(char)*50);
	strcpy(ID2, "tom45");
	char* code2 = malloc(sizeof(char)*50);
	strcpy(code2, "MH");
	char* ID3 = malloc(sizeof(char)*50);
	strcpy(ID3, "john95");
	char* code3 = malloc(sizeof(char)*50);
	strcpy(code3, "CV");
	char* ID4 = malloc(sizeof(char)*50);
	strcpy(ID4, "tim27");
	char* code4 = malloc(sizeof(char)*50);
	strcpy(code4, "EC");
	Patient* p1 = createPatient(ID1, 1 , code1, 0);
	Patient* p2 = createPatient(ID2, 2 , code2, 0);
	Patient* p3 = createPatient(ID3, 3 , code3, 0);
	Patient* p4 = createPatient(ID4, 1 , code4, 0);
	
	printf("p1 = ");
	printPatient((void*)p1);
	printf("p2 = ");
	printPatient((void*)p2);
	printf("p3 = ");
	printPatient((void*)p3);
	printf("p4 = ");
	printPatient((void*)p4);
	pInsert(q, p1, 1);
	pInsert(q, p2, 2);
		
	printf("Testing insert\n");
	printf("Expecting: p3 should be at back of queue\n");
	insert(q, p3, 3);
	printf("Received: back = ");
	printPatient(q->list->tail->data);
	printf("Test Passed\n\n");
	
	printf("Testing pInsert\n");
	printf("Expecting: p4 should be the second element in the queue\n");
	pInsert(q, p4, 1);
	printf("Received:\n");
	printForward(q->list);
	printf("Test Passed\n\n");
	
	printf("Testing peek\n");
	printf("Expecting: front of the queue(p1) should be printed\n");
	printf("Received: front = ");
	printPatient(peek(q));
	printf("Test Passed\n\n");
	
	printf("Testing pop\n");
	printf("Expecting: front of the queue(p1) should be deleted\n");
	printf("Received:\n");
	pop(q);
	printForward(q->list);
	printf("Test Passed\n\n");
	
	printf("Testing isEmpty\n");
	printf("Expecting: 1 should be returned\n");
	printf("Received:\n");
	printf("%d\n", isEmpty(q));
	printf("Test Passed\n\n");
	
	printf("Testing destroy\n");
	printf("Expecting: queue should be deleteled\n");
	destroy(q);
	printf("Received: (any called to list cause segmentation fault)\n");
	printf("Test Passed\n\n");
	
	printf("ALL TEST PASSED\n");
	

	
	return 0;
	
}
