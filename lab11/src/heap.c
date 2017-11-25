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
    size_t index = heap->currentSize;
    Node* insertNode = createHeapNode(data);
    heap->heapArray[index] = insertNode;
    heap->currentSize++;
    heapify(heap, 0);
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
    void* temp;
    if(i >= heap->currentSize)
    {
        return;
    }
    Node* curNode = heap->heapArray[i];
    size_t lIndex = getLeftChildIndex(i);
    size_t rIndex = getRightChildIndex(i);
    if(lIndex < heap->currentSize && rIndex < heap->currentSize)
    {
        Node* lcNode = heap->heapArray[lIndex];
        Node* rcNode = heap->heapArray[rIndex];
        int comp = heap->compare(rcNode->data, lcNode->data);
        if(comp == 1)
        {
            comp = heap->compare(curNode->data, lcNode->data);
            if(comp == 1)
            {
                temp = curNode->data;
                curNode = lcNode->data;
                lcNode->data = temp;
            }
        }
        else
        {
            comp = heap->compare(curNode->data, rcNode->data);
            if(comp == 1)
            {
                temp = curNode->data;
                curNode = rcNode->data;
                rcNode->data = temp;
            }
        }
    }
    else if(lIndex < heap->currentSize)
    {
        Node* lcNode = heap->heapArray[lIndex];

        int comp = heap->compare(curNode->data, lcNode->data);
        if(comp == 1)
        {
            temp = curNode->data;
            curNode = lcNode->data;
            lcNode->data = temp;
        }
    }
    else if(rIndex < heap->currentSize)
    {
        Node* rcNode = heap->heapArray[rIndex];
        int comp = heap->compare(curNode->data, rcNode->data);
        if(comp == 1)
        {
            temp = curNode->data;
            curNode = rcNode->data;
            rcNode->data = temp;
        }
    }
    heapify(heap, lIndex);
    heapify(heap, rIndex);
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
    size_t leftChildIndex = (2*index) + 1;
	return leftChildIndex;
}

size_t getRightChildIndex(size_t index)
{
    size_t rightChildIndex = (2*index) + 2;
	return rightChildIndex;
}

size_t getParentIndex(size_t index)
{
    size_t parentIndex = (index-1)/2;
    return parentIndex;
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
    Node* curNode = heap->heapArray[0];
    size_t index = 0;
    for(index = 0;index < heap->currentSize; index++)
    {
        curNode = heap->heapArray[index];
        printFunc(curNode->data);
    }
}
