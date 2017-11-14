#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

/**
 * Stores basic car information.
 */
typedef struct car {
    int time;
    char dir;
    char turn;
    double compTime;
    double frontTime;
} Car;

/**
 * creates a car
 * @param  time the car arrvies
 * @param  direction (E, S, N, W)
 * @param  what way the car is turning
 * @param  the time the car complete the intersection 
 * @param the time the car got the the front on the intersection
 * @return       a dynamically created car.
 */
Car* createCar(int time, char dir, char turn, double compTime, double frontTime);

/**
 * Get time the car arrives
 * @param  c Car
 * @return   int time
 */
int getTime(Car* c);

/**
 * Return a car's directtion
 * @param  c Car
 * @return   char dir
 */
char getDir(Car* c);

/**
 * Return the direction the car is turning
 * @param c Car
 * @return char turn
 */
char getTurn(Car* c);

/**
 * @param c Car
 * @return double compTime
 */
double getCompTime(Car* c);

/**
 * @param c Car
 * @param double frontTime
 * 
 */
double getFrontTime(Car* c);

void printCar(void *toBePrinted);

void deleteCar(void *toBeDeleted);

int compareCar(const void *first,const void *second);
 
#endif // CAR_H_INCLUDED
