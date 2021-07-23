#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "sorter.h"
#include "item.h"

static bool goes_before(unsigned int x, unsigned int y) {
    bool r=false;
    if (x>y){
        r=true;
    }
    return r;
}

static void swap(item_t *items, unsigned int i, unsigned int j){
	item_t tmp;
	tmp = items[i];
	items[i]=items[j];
	items[j]=tmp;
}


static void insert(item_t *items, unsigned int i) {
    	int j=i;
	while (j>=1 && goes_before(item_value(items[j]), item_value(items[j-1]))) {
		swap(items,j,j-1);
		j= j-1;
	}
}

void insertion_sort(item_t *items, unsigned int array_length) {
    for (unsigned int i =1u; i < array_length; ++i){    
		insert(items,i);
    }
}

