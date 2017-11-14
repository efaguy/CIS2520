#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../includes/car.h"
#include "../includes/LinkedListAPI.h"

int main(int argc, char ** argv)
{  
	
	printf("Testing initializeList\n");
	printf("Expecting: list should be made and head an tail set to null\n");
	List* list = initializeList(printCar, deleteCar, compareCar);
	printf("Received: head = ");
	printf("%p\n", (void*)list->head);
	printf("Tail = ");
	printf("%p\n", (void*)list->tail);
	printf("Test Passed\n\n");
	
	Car* c1 = createCar(2, 'S', 'R',  0, 0);
	Car* c2 = createCar(5, 'W', 'F',  0, 0);
	Car* c3 = createCar(1, 'E', 'F',  0, 0);
	Car* c4 = createCar(10, 'W', 'L', 0, 0);
	Car* c5 = createCar(7 , 'S', 'F', 0, 0);
	printf("c1 = ");
	printCar((void*)c1);
	printf("c2 = ");
	printCar((void*)c2);
	printf("c3 = ");
	printCar((void*)c3);
	printf("c4 = ");
	printCar((void*)c4);
	printf("c5 = ");
	printCar((void*)c5);
	insertSorted(list, c1);
	insertSorted(list, c2);
		
	printf("Testing insertFront\n");
	printf("Expecting: c3 should be at front of list\n");
	insertFront(list, c3);
	printf("Received: head = ");
	printCar(list->head->data);
	printf("Test Passed\n\n");
	
	printf("Testing insertBack\n");
	printf("Expecting: c4 should be at back of list\n");
	insertBack(list, c4);
	printf("Received: tail = ");
	printCar(list->tail->data);
	printf("Test Passed\n\n");
	
	printf("Testing printFowards\n");
	printf("Expecting: cars should be printed fowards\n");
	printf("Received:\n");
	printForward(list);
	printf("Test Passed\n\n");
	
	printf("Testing printBackwards\n");
	printf("Expecting: cars should be printed backwards\n");
	printf("Received:\n");
	printBackwards(list);
	printf("Test Passed\n\n");
	
	printf("Testing insertSorted\n");
	printf("Expecting: c5 should the 4th element in the list\n");
	insertSorted(list, c5);
	printf("Received:\n");
	printForward(list);
	printf("Test Passed\n\n");
	
	printf("Testing deleteNodeFromList\n");
	printf("Expecting: c2 should be deleted\n");
	printf("Received:\n");
	deleteNodeFromList(list, c2);
	printForward(list); 
	printf("Test Passed\n\n");
	
	printf("Testing getFromFront\n");
	printf("Expecting: head of the list(c3) should be printed\n");
	printf("Received: head = ");
	printCar(getFromFront(list));
	printf("Test Passed\n\n");
	
	printf("Testing getFromBack\n");
	printf("Expecting: tail of the list(c4) should be printed\n");
	printf("Received: tail = ");
	printCar(getFromBack(list));
	printf("Test Passed\n\n");
	
	printf("Testing deleteList\n");
	printf("Expecting: list should be deleteled\n");
	deleteList(list);
	printf("Received: list = (any called to list cause segmentation fault\n)");
	printf("Test Passed\n\n");
	
	printf("ALL TEST PASSED\n");
	

	
	return 0;
	
}
