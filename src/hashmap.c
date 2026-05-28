#include "hashmap.h"
#include "hash_functions.h"

#include <stdio.h>

#define HASHMAP_SIZE 23
#define REHASHING_THRESHOLD 0.7
#define max_chaining 8

typedef void* any_t;

typedef struct bucket_t{
    any_t *key;
    any_t *value;
    _Bool occupied;
    struct bucket *next;
}bucket;

typedef struct map_t{
    size_t hashmap_size;
    bucket* hashmap_element;
}map;
