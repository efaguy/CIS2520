#include <stdio.h>
#include <stdlib.h>
#include "HeapAPI.h"
#include "integer.h"

/**
 * Setup a heap for testing and initialize it with testing data.
 * This is not meant to represent proper testing but to provide visual information.
 * This should help identify if your heap is working correctly.
 */
Heap* createAndinitializeHeap();

int main( int argc, char ** argv)
{
	// Initialize the heap
	Heap *heap = createAndinitializeHeap();

	// Print the Heap inorder
	printf("\nPrint in order\n");
	printHeap(heap,printData);

	// Print and destroy the heap. The heap will adjust after each delete to maintain the heap property. 
	printf("\nPrint and destory\n");
	int index = 0;
	int  data[] = {4,6,7,8,9,10, 11,12,13,14,15,16,17,18,19};
	while( currentSize(heap) > 0 )
	{
		printData( getRoot(heap) );
		if( compareData(getRoot(heap), &data[index]) != 0 )
			printf("Test Failed at id=%d, value=%d\n", index, data[index]);
		index++;
		deleteRoot(heap);
	}

	// Free the heap memory.
	deleteHeap(heap);

	return 0;
}

Heap* createAndinitializeHeap( )
{
	Heap *heap = createHeap(31,&destroyData,&compareData);

	// Create some test data to store in the Heap.
	int  data[] = {10, 11,12,13,14,15,16,17,18,19,9,8,7,6,4};
	int sizeData = sizeof(data)/sizeof(data[0]);
	printf("Reading in data\n");
	int * ip = NULL;
	for( int  i= 0; i < sizeData;i++)
	{
		ip = malloc(sizeof(int));
		*ip = data[i];
		printData(ip);
		insertHeapNode(heap,ip);
	}
	return heap;
}



