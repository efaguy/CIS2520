#include "HeapAPI.h"

/**
 * Internal functions to search for the max element between the data stored at index i
 * and the left child. This function will use compares data using the function pointer and return the index of the maximum item.
 */
size_t findMaxLeft(Heap *heap,size_t i); 

/**
 * Internal functions to search for the max element between the data stored at index current
 * and the right child. This function will use compares data using the function pointer and return the index of the maximum item.
 */
size_t findMaxRight(Heap *heap,size_t curr, size_t i); 

/**************************************************************************************************************************/

Heap *createHeap(size_t initialSize, void (*destroyDataFP)(void *data),int (*compareFP)(const void *first, const void *second)){
    Heap *heap;
    if(!(heap = malloc(sizeof(Heap)))){
        fprintf(stderr,"Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    if(!(heap->heapArray = malloc(sizeof(Node)*initialSize))){
        fprintf(stderr,"Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    heap->type = MIN_HEAP;
    heap->currentSize = 0;
    heap->maxSize = initialSize;
    heap->destroyData = destroyDataFP;
    heap->compare = compareFP;
    return heap;
}

Node *createHeapNode(void *data){
    Node *node;
    node = malloc(sizeof(Node));
    node->data = data;
    return node;
}

void insertHeapNode(Heap *heap, void *data){
    //TODO: For lab 11 students must recreate this function

	// This function inserts data into the heap.
	// It should check for the next available position in the tree.
	// Then it should ensure that the heap's properties remain consistent.
}

void deleteRoot(Heap *heap) {
    Node *temp;
    if(heap->currentSize>0) {
        temp = heap->heapArray[0];
        (heap->currentSize)--;
        heap->heapArray[0] = heap->heapArray[heap->currentSize];
        heap->destroyData(temp);
        heapify(heap, 0) ;
    } else {
        fprintf(stderr,"Heap is empty.\n") ;
	}
}

void deleteHeap(Heap *heap){
    size_t i;
    i = heap->currentSize;
    while(i>0){
        deleteRoot(heap);
        i--;
    }
    free(heap->heapArray);
    free(heap);
}

void* getRoot(Heap *heap){
    return heap->heapArray[0]->data;
}

void heapify(Heap *heap, size_t i){
    //TODO: For lab 11 students must recreate this function

	// This function adjust the heap to ensure that it remains in proper order.
	// The adjustment occurs with the heap contianer.
}


size_t findMaxLeft(Heap *heap,size_t i){
    size_t  leftIdx = getLeftChildIndex( i );
    if( leftIdx < heap->currentSize && heap->compare(heap->heapArray[leftIdx]->data,heap->heapArray[i]->data) > 0){
        return leftIdx;
    }
    return i;
}

size_t findMaxRight(Heap *heap,size_t curr, size_t i){
    size_t rightIdx = getRightChildIndex( curr );
    if( rightIdx < heap->currentSize && heap->compare(heap->heapArray[rightIdx]->data,heap->heapArray[i]->data) > 0){
      return rightIdx;
    }
    return i;
}


size_t getLeftChildIndex(size_t index)
{
    //TODO: For lab 11 students must recreate this function
	// helper to quickly calculate the left child from index ( ie index is the parent )
	return 0;
}

size_t getRightChildIndex(size_t index)
{
    //TODO: For lab 11 students must recreate this function
	// helper to quickly calculate the right child from index ( ie index is the parent )
	return 0;
}

size_t getParentIndex(size_t index)
{
    //TODO: For lab 11 students must recreate this function
	// helper to quickly calculate the parent index of a child node. 
	return 0;
}

size_t currentSize(Heap* heap)
{
    return heap->currentSize;
}

void* search(Heap* heap, void* data)
{       
    for(size_t i =0; i < currentSize(heap);i++) 
    {
        if( heap->compare(data,heap->heapArray[i]->data) == 0)
            return heap->heapArray[i]->data;
    }
    return NULL;
}


void printHeap(Heap* heap, void (*printFunc)(void*) )
{
    //TODO: For lab 11 students must recreate this function
	// Print a BFS version of the Heap Array
	// This function should be iterative for BFS.
}
