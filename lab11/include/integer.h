#ifndef INTEGER_H
#define INTEGER_H

#include <stdio.h>
#include <stdlib.h>
/**
 * Free integer data
 */
void destroyData( void * data );

/**
 * Compare integer data 
 * Retur 0 if equal, 1 if second is larger, -1 if second small */
int compareData( const void *first, const void* second );

/**
 * Display integer data
 */
void printData( void * data );

#endif
