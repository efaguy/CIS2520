#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/book.h"

/**
 * creates a book
 * @param  title static string of title
 * @param  price double
 * @return       a dynamically created Book.
 */
Book* createBook( char * title, double price )
{
    Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}

/**
 * Get price of book
 * @param  b Book
 * @return   Double price
 */
double getPrice( Book * b )
{
    return b->price;
}

/**
 * Return a books name
 * @param  b Book
 * @return   char* string of name
 */
char* getName( Book *b )
{
	return b->name;
}

/**
 * Display a book's name and price.
 * @param b [Book]
 */
void printBook( void * v )
{
    Book * b = (Book *) v;
    printf("%s : %.2f\n", getName(b), getPrice(b) );
}
