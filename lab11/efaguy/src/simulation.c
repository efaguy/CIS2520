#include <stdio.h>
#include <stdlib.h>
#include "HeapAPI.h"
#include "video.h"
#include "simulation.h"
#include "menu.h"

Heap* initializeStaticData()
{
	// Initialize the heap
	Heap *heap = createHeap(31,&deleteVideo,&compareVideo);

	// Add some static content
	Video* v1 = createVideo("Wonder Women");
	insertHeapNode(heap,v1);

	Video* v2 = createVideo("Batman Begins");
	insertHeapNode(heap,v2);

	Video* v3 = createVideo("Batman Continues");
	insertHeapNode(heap,v3);

	Video* v4 = createVideo("Batman Ends");
	insertHeapNode(heap,v4);

	Video* v5 = createVideo("Spider-man 15 Ben dies again");
	insertHeapNode(heap,v5);

	// Print the Heap inorder just to make sure things are looking good.
	printf("\nPrint in order\n");
	printHeap(heap, printVideo);	

	return heap;
}

void runSimulation()
{
	Heap* heap = initializeStaticData();

	int menuChoice = 0;
	char line[80];
	while( menuChoice != 9)
	{
		// Print the menu and read some characters after.
		printMenu();
		fgets(line,80,stdin);
		menuChoice = atoi(line);
		
		if(menuChoice == 1)
		{
			Video *v = getVideo();
			addVideo(heap,v);
		}
		else if(menuChoice == 2)
		{
			watchVideo(heap);
		}
		else if(menuChoice == 3)
		{
			printHeap( heap, printVideo);	
		}
		else if(menuChoice == 9)
		{
			printf("\nThank you for using this program!\n");
		}
	}

	// Free the heap memory.
	deleteHeap(heap);
}
