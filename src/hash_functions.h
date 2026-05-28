#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <stddef.h>

int int_hashing(int num, int hashmap_size);
int float_hashing(float num, int hashmap_size);
int string_hashing(char* string, size_t size, int hashmap_size);
int compound_hashing(int* compound_key, size_t size, int hashmap_size);

#endif
