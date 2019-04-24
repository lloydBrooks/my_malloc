#include <stdio.h>

/*
 * Lloyd Brooks
 * Homework 6
 */

/*
 * Used malloc to create a pool of memory of the specified size.
 */
void create_pool(int size);

/*
 * Used to request a piece of memory form the pool.
 */
void* my_malloc(int size);

/*
 * Used to return a piece of memory to the pool.
 */
void my_free(void* block);