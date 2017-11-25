/**
 * @file HeapAPI.h
 * @author Michael Ellis
 * @author James Fraser (Modified)
 * @date March 2017
 * @brief File containing the function definitions of a heap
 */

#ifndef _HEAP_API_
#define _HEAP_API_

#include <stdio.h>
#include <stdlib.h>

/**macro for HEAP_TYPE data type. Signifies that this is a min heap.*/
#define MIN_HEAP 1

/**macro for HEAP_TYPE data type, used to determine if the heap is min or max.*/
#define HEAP_TYPE unsigned char
/**
*Node of the Heap. 
**/
typedef struct Node
{
	void *data; ///< pointer to generic data that is to be stored in the heap
} Node;

/**
*Heap structure
**/
typedef struct Heap
{
	size_t currentSize; ///< unsigned integer that represents the current size of the heap
    size_t maxSize; ///< unsigned integer that represents the maximum size of the heap
	Node **heapArray; ///< array that contains all of the heap nodes
    HEAP_TYPE type; ///< flag for choosing between min and max heap
	void (*destroyData)(void *data); ///< function pointer to a function to delete a single piece of data from the heap
    int (*compare)(const void *first, const void *second); ///< function pointer to a comparison function for the purpose of inserting and deleting elements
}Heap;


/**Function to allocate memory to the heap and point the heap to the appropriate functions. Allocates memory to the heap based on the size given.
 *@return pointer to the heap
 *@param initialSize initial size of the heap
 *@param htype flag to choose whether to start the heap as a min heap or max heap. Takes in values MIN_HEAP and MAX_HEAP
 *@param compareFP function pointer to a function that compares two pieces of data.
 *@param destroyDataFP function pointer to a function to delete a single piece of data from the heap
 *@param printNodeFP function pointer to a function that prints out a data element of the heap
 *@return pointer to the heap
 **/
Heap *createHeap(size_t initialSize, void (*destroyDataFP)(void *data),int (*compareFP)(const void *first, const void *second));

/**Function for creating a node for a heap.
 *@pre Node must be cast to void pointer before being added.  *@post Node is valid and able to be added to a heap
 *@param data is a generic pointer to any data type that is to be stored in the heap.
 *@return returns a node for a heap
 **/
Node* createHeapNode(void *data);

/**Inserts a Node into the heap. Uses createHeapNode to place the data in a Node structure, and then puts the newly
 *created Node in the heap by adding at the bottom and comparing it to each parent node until it fits the Heap structure.
 *If the heap is a min heap, if the Node is lesser than the parent, it is swapped. The opposite is true for a max heap.
 *@pre Heap must exist and have data allocated to it
 *@param heap Pointer to a heap
 *@param data Pointer to generic data that is to be inserted into the heap
**/
void insertHeapNode(Heap *heap, void *data);

/**Function to remove the maximum or minimum Node of the heap (depending on min heap or max heap).
 *Once the Node has been deleted, the Node at the deepest point in the Heap is placed in the min/max position.
 *Finally, the heap is heapified to maintain heap property.
 *@pre Heap must exist and have memory allocated to it
 *@param heap Pointer to a heap.
 **/
void deleteRoot(Heap *heap);

/**Function to rearrange a heap to maintain heap property. Starting at the min/max, each Node is compared with its
 *two children to determine the smallest/largest of the three. If the parent is smaller/larger than the child,
 *it is swapped. Heapify is then recursively called on the child in order to continue heapifying until it reaches the bottom of the heap.
 *@param heap Pointer to a heap to be heapified
 *@param index Pointer to starting index. This index is considered the parent Node of the iteration, and should start at 0 on the initial heapify call.
 **/
void heapify(Heap *heap, size_t index);

/**Function to return the minimum or maximum value Node, depending on the type of heap
 *@param heap Pointer to a heap to get the max or min from.
 *@return Pointer to max or min node. With an array implementation this will be heap[0].
 **/
void* getRoot(Heap *heap);

/**Function delete a heap. This function calls deleteMinOrMax the same amount of times as the size of the
 *heap, which heapifies after each deletion. Finally, it frees the Heap structure.
 *@param heap Pointer of a heap to be deleted.
 **/
void deleteHeap(Heap *heap);


/**
 * getLeftChildIndex - this function takes an index and returns the position of the left child in a Heap.
 * @param  index 
 * @return       index of left child
 */
size_t getLeftChildIndex(size_t index);

/**
 * getRightChildIndex - this function takes an index and returns the position of the right child in a Heap.
 * @param  index 
 * @return       index of left child
 */
size_t getRightChildIndex(size_t index);

/**
 * getParentIndex - this function takes an index and returns the position of the parent node in a Heap.
 * @param  index 
 * @return       index of left child
 */
size_t getParentIndex(size_t index );


/**
 * currentSize - returns the current size of the Heap. Value is not calculated but stored.
 * @param  heap 
 * @return     count of items in the heap.
 */
size_t currentSize( Heap* heap );

/**
 * search - Search a Heap (Note this is not done efficiently based on heap properties).
 *                      Instead it's a linear solution so as not to provide answers.
 * @param heap [description]
 * @param data Search for data based on the comparison function.
 */
void* search(Heap* heap, void* data);


/**
 * printHeap  will print heap data based on the printFunction.
 *             Note, this function only iterates the array based heap.
 */
void  printHeap(Heap *heap, void (*printFunc)(void*) );

#endif


