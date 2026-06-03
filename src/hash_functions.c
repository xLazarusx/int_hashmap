#include "hash_functions.h"

int int_hashing(int *num, int hashmap_size){
    int hash = (*num) % hashmap_size;

    if (hash < 0){
        hash = hash * (-1);
    }

    return hash;
}
