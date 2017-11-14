#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../includes/car.h"
#include "../includes/LinkedListAPI.h"


int main(int argc, char ** argv)
{   
	FILE * fp = NULL;
	char dir;
	char turn;
	int time;
	double curTime = 1; //Current Time
	double relTime = 1; //Relative Time
	//Initialize 5 list, one for each direction of travel and one for cars that have gone thought the intersection
	List* carsN = initializeList(printCar, deleteCar, compareCar);
	List* carsE = initializeList(printCar, deleteCar, compareCar);
	List* carsS = initializeList(printCar, deleteCar, compareCar);
	List* carsW = initializeList(printCar, deleteCar, compareCar);
	List* doneCars = initializeList(printCar, deleteCar, compareCar);
	//Open the file
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("Error opening file\n");
		return-1;
	}
	//Parse the input and out it in the appropriate list
	while((dir = getc(fp)) != EOF)
	{
		getc(fp);
		turn = getc(fp);
		getc(fp);
		fscanf(fp, "%d", &time);
		if(dir == 'N')
		{
			insertSorted(carsN, createCar(time, dir, turn, 0, 0));
		}
		else if(dir == 'E')
		{
			insertSorted(carsE, createCar(time, dir, turn, 0, 0));
		}
		else if(dir == 'S')
		{
			insertSorted(carsS, createCar(time, dir, turn, 0, 0));
		}
		else if(dir == 'W')
		{
			insertSorted(carsW, createCar(time, dir, turn, 0, 0));
		}
		//Move to the next line
		while(getc(fp) != '\n')
		{
			
		}
	}
	Node* n = NULL;
	Car* c = NULL;
	//While at least one list still has a car in it
	while(carsN->head != NULL || carsE->head != NULL || carsS->head != NULL || carsW->head != NULL)
	{
		//relTime will stay between 1 and 57. i.e. if curTime = 58, relTime = 2
		relTime = curTime;		
		while(relTime >= 57)
		{
			relTime = relTime - 56; 
		}
		//North Green light
		if(relTime < 11)
		{
			n = carsN->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					//Check if the car is already at the intersection when the light turns green so the right frontTime can be given
					if(relTime == 1)
					{
						if(c->turn == 'F')
						{
							//Insert the car into the doneCars list, remove it from its original list and add the appropriate time to the counter
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, c->time));
							deleteNodeFromList(carsN, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, c->time));
							deleteNodeFromList(carsN, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, c->time));
							deleteNodeFromList(carsN, n->data);
							curTime += 2.5;
						}
					}
					else 
					{
						if(c->turn == 'F')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, curTime));
							deleteNodeFromList(carsN, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, curTime));
							deleteNodeFromList(carsN, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
							deleteNodeFromList(carsN, n->data);
							curTime += 2.5;
						}
					}
				}
				else				
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		//North Yellow
		else if(relTime == 11)
		{
			n = carsN->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					if(c->turn == 'L')
					{
						insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
						deleteNodeFromList(carsN, n->data);
						curTime += 2.5;
					}
					else
					{
						curTime += 0.5;
					}
				}
				else 
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		//East green light
		else if(relTime >= 15 && relTime < 25)
		{
			n = carsE->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					if(relTime == 15)
					{
						if(c->turn == 'F')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, c->time));
							deleteNodeFromList(carsE, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, c->time));
							deleteNodeFromList(carsE, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, c->time));
							deleteNodeFromList(carsE, n->data);
							curTime += 2.5;
						}
					}
					else
					{
						if(c->turn == 'F')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, curTime));
							deleteNodeFromList(carsE, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, curTime));
							deleteNodeFromList(carsE, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
							deleteNodeFromList(carsE, n->data);
							curTime += 2.5;
						}	
					}
				}
				else
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		//East Yellow light
		else if(relTime == 25)
		{
			n = carsE->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					if(c->turn == 'L')
					{
						insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
						deleteNodeFromList(carsE, n->data);
						curTime += 2.5;
					}
					else
					{
						curTime += 0.5;
					}
				}
				else 
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		//South Green Light
		else if(relTime >= 29 && relTime < 39)
		{
			n = carsS->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					if(relTime == 29)
					{
						if(c->turn == 'F')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, c->time));
							deleteNodeFromList(carsS, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, c->time));
							deleteNodeFromList(carsS, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, c->time));
							deleteNodeFromList(carsS, n->data);
							curTime += 2.5;
						}
					}
					else
					{
						if(c->turn == 'F')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, curTime));
							deleteNodeFromList(carsS, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, curTime));
							deleteNodeFromList(carsS, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
							deleteNodeFromList(carsS, n->data);
							curTime += 2.5;
						}
					}
				}
				else
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		//South Yellow Light
		else if(relTime == 39)
		{
			n = carsS->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					if(c->turn == 'L')
					{
						insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
						deleteNodeFromList(carsS, n->data);
						curTime += 2.5;
					}
					else
					{
						curTime += 0.5;
					}
				}
				else 
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		//West Green Light
		else if(relTime >= 43 && relTime < 53)
		{
			n = carsW->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					if(relTime == 43)
					{
						if(c->turn == 'F')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, c->time));
							deleteNodeFromList(carsW, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, c->time));
							deleteNodeFromList(carsW, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, c->time));
							deleteNodeFromList(carsW, n->data);
							curTime += 2.5;
						}
					}
					else
					{
						if(c->turn == 'F')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2, curTime));
							deleteNodeFromList(carsW, n->data);
							curTime += 2;
						}
						else if(c->turn == 'R')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 1, curTime));
							deleteNodeFromList(carsW, n->data);
							curTime += 1;
						}
						else if(c->turn == 'L')
						{
							insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
							deleteNodeFromList(carsW, n->data);
							curTime += 2.5;
						}
					}
				}
				else
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		//West Yellow Light
		else if(relTime == 53)
		{
			n = carsW->head;
			if(n != NULL)
			{
				c = (Car*)n->data;
				if(c->time <= curTime)
				{
					if(c->turn == 'L')
					{
						insertBack(doneCars, createCar(c->time, c->dir, c->turn, curTime + 2.5, curTime));
						deleteNodeFromList(carsW, n->data);
						curTime += 2.5;
					}
					else
					{
						curTime += 0.5;
					}
				}
				else 
				{
					curTime += 0.5;
				}
			}
			else
			{
				curTime += 0.5;
			}
		}
		else
		{
			curTime += 0.5;
		}
	}
	//Print the final output
	printf("Initial Vehicle Information\tIntersection Arrival Time\tCompleted at Time\n");
	printForward(doneCars);
	deleteList(carsN);
	deleteList(carsS);
	deleteList(carsE);
	deleteList(carsW);
	deleteList(doneCars);
    return 0;
}
