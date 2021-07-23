#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>
#include "item.h"

void insertion_sort(item_t *items, unsigned int array_length);
/*
    Sort the array using the Insertion sort algorithm. The resulting sort
    will be descending according to the goes_before funtion.

*/

#endif
