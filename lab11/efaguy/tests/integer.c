#include "integer.h"

void destroyData( void * data )
{
	int* p = (int*)data;
	free(p);
	p = NULL;
}

int compareData( const void *first, const void* second)
{
	int fi = *((int*)first);
	int si = *((int*)second);
	if(si == fi)
		return 0;
	if( si > fi)
		return 1;
	return -1;
}

void printData( void * data)
{
	int fi = *((int*)data);
	printf("%d\n", fi);
}
