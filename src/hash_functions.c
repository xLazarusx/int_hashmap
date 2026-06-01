#include "hash_functions.h"
#include <string.h>

#define R 31
#define DEFAULT 0

int int_hashing(int *num, int hashmap_size){
    int hash = (*num) % hashmap_size;

    if (hash < 0){
        hash = hash * (-1);
    }

    return hash;
}

/*
int float_hashing(float num, int hashmap_size){
    int int_num = 0;
    int *ptr_int_num = &int_num;
    float *ptr_num = &num;

    memcpy(ptr_int_num, ptr_num, sizeof(int));

    return int_num % hashmap_size;
}

int string_hashing(char *string, size_t size, int hashmap_size){

    if (size == 0) {
        return DEFAULT;
    }

    int hash = 0;

    for (size_t index = 0; index < size-1; index++) {
        hash = (hash * R + (int)string[index]) % hashmap_size;
    }

    return hash;
}

int compound_hashing(int *compound_key, size_t size, int hashmap_size){
    int hash = 0;

    for (size_t index = 0; index < size; index++) {
        hash = (hash * R + compound_key[index]) % hashmap_size;
    }

    return hash;
}
*/
