#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/car.h"

/**
 * creates a car
 * @param  time the car arrvies
 * @param  direction (E, S, N, W)
 * @param  what way the car is turning
 * @param  the time the car complete the intersection 
 * @param the time the car got the the front on the intersection
 * @return       a dynamically created car.
 */
Car* createCar(int time, char dir, char turn, double compTime, double frontTime)
{
	Car* c = malloc(sizeof(Car));
	c->time = time;
	c->dir = dir;
	c->turn = turn;
	c->compTime = compTime;
	c->frontTime = frontTime;
	return c;
}
/**
 * Get time the car arrives
 * @param  c Car
 * @return   int time
 */
int getTime(Car* c)
{
	return c->time;
}
/**
 * Return a car's directtion
 * @param  c Car
 * @return   char dir
 */
char getDir(Car* c)
{
	return c->dir;
}

/**
 * Return the direction the car is turning
 * @param c Car
 * @return char turn
 */
char getTurn(Car* c) 
{
	return c->turn;
}

/**
 * @param c Car
 * @return double compTime
 */

double getCompTime(Car* c)
{
	return c->compTime;
}

/**
 * @param c Car
 * @param double frontTime
 * 
 */
double getFrontTime(Car* c)
{
	return c->frontTime;
}

void printCar(void *toBePrinted)
{
	Car* c = (Car*)toBePrinted;
	printf("%c %c %d\t\t\t\t%.1f\t\t\t\t%.1f\n",c->dir, c->turn, c->time, c->frontTime, c->compTime);
}

void deleteCar(void *toBeDeleted)
{
	Car* c = (Car*)toBeDeleted;
	free(c);
}

int compareCar(const void *first,const void *second)
{
	Car* c1 = (Car*)first;
	Car* c2 = (Car*)second;
	
	if(c1->time > c2->time)
	{
		return 1;
	}
	else if (c1->time < c2->time)
	{
		return -1;
	}
	else if (c1->time == c2->time)
	{
		return 0;
	}
	return 0;
}
