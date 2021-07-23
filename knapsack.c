#include <assert.h>
#include <stdlib.h>
#include "knapsack.h"

static value_t max(value_t a, value_t b) {
    value_t result = b;
    if (a > b) {
        result = a;
    }
    return result;
}

value_t knapsack_backtracking(item_t *items, unsigned int array_length, weight_t max_weight) {
    value_t result;
    unsigned int i = array_length;
    unsigned int j = max_weight;
    if(j==0u) {
        result = 0u;
    } else if (j>0u && i==0u) {
        result = 0u;
    } else if (item_weight(items[i-1]) > j && j>0u && i>0u) {
        result = knapsack_backtracking(items,i-1,j);
    } else {
        result = max(knapsack_backtracking(items,i-1,j), 
          item_value(items[i-1]) + knapsack_backtracking(items,i-1,j-item_weight(items[i-1])));
    }
    return result; 
}

static void print_mochila(value_t* *matriz, value_t filas, value_t columnas) {
    for (unsigned int i=0;i<filas; ++i) {
        for (unsigned int j=0;j<columnas; ++j) {
            printf("%4u ", matriz[i][j]);
        }
        puts("");
    }
}

value_t knapsack_dynamic(item_t *items, unsigned array_length, weight_t max_weight) {
    value_t result=0u;
    unsigned int length = array_length+1;
    unsigned int capacity = max_weight+1;
    value_t **mochila = calloc(length,sizeof(value_t*));

    for (unsigned int i=0u; i<length; ++i) {
        mochila[i] = calloc(capacity,sizeof(value_t));
    }
    for (unsigned int i=0u; i<length; ++i) {
        mochila[i][0u] = 0u;
    }
    for (unsigned int j=1u; j<capacity; ++j) {
        mochila[0u][j] = 0u;
    }
    for (unsigned int i=1u; i<length; ++i) {
        for (unsigned int j=1u; j<capacity; ++j) {
            if (item_weight(items[i-1]) > j) {
                mochila[i][j] = mochila[i-1][j];
            } else {
                mochila[i][j] = 
                    max(mochila[i-1][j], item_value(items[i-1]) + mochila[i-1][j-item_weight(items[i-1])]);
            }
        }
    }
    result = mochila[array_length][max_weight];
    print_mochila(mochila, length, capacity);
    

    for (unsigned int i=0u; i<length; ++i) {
        free(mochila[i]);
    }
    free(mochila);
    mochila = NULL;
    return result;
}

value_t knapsack_dynamic_selection(item_t *items, bool *selected, unsigned int array_length, weight_t max_weight) {
    value_t result=0u;
    unsigned int length = array_length+1, capacity = max_weight+1;
    unsigned int I = array_length, W = max_weight;
    value_t* *mochila = calloc(length,sizeof(value_t*));

    for (unsigned int i=0u; i<length; ++i) {
        mochila[i] = calloc(capacity,sizeof(value_t));
    }
    for (unsigned int i=0u; i<length; ++i) {
        mochila[i][0u] = 0u;
    }
    for (unsigned int j=0u; j<capacity; ++j) {
        mochila[0u][j] = 0u;
    }
    for (unsigned int i=1u; i<length; ++i) {
        for (unsigned int j=1u; j<capacity; ++j) {
            if (item_weight(items[i-1]) > j) {
                mochila[i][j] = mochila[i-1][j];
            } else {
                mochila[i][j] = 
                        max(mochila[i-1][j], item_value(items[i-1]) + mochila[i-1][j-item_weight(items[i-1])]);
            }
        }
    }
    result = mochila[array_length][max_weight];
    print_mochila(mochila, length, capacity);

    while (mochila[I][W] > 0u) {
        if (mochila[I][W] == mochila[I-1][W]) { // si no se uso el item le asigno false
            selected[I-1] = false;
        } else {  // se uso el item, le asigno true
            assert(mochila[I][W] == item_value(items[I-1]) + mochila[I-1][W-item_weight(items[I-1])]);
            assert(item_weight(items[I-1]) <= max_weight);
            selected[I-1] = true;
            W = W - item_weight(items[I-1]);
        }
        I--;
    }    
    for (unsigned int i=0u; i<length; ++i) {
        free(mochila[i]);
    }
    free(mochila);
    mochila = NULL;
    return result;
}
