#include "hashmap.h"
#include "hash_functions.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define INITIAL_HASHMAP_SIZE 23
#define REHASHING_THRESHOLD 0.7

typedef struct bucket_t bucket;

typedef struct bucket_t{
    int *key;
    int *value;
    _Bool used;
}bucket;

static int hashmap_size = INITIAL_HASHMAP_SIZE;
static int element_count;
static bucket *hashmap[INITIAL_HASHMAP_SIZE] = { NULL };

int linear_search (int index, int key) {

    int tmp_index = index;

    if (key == 0) {
        while (hashmap[index] == NULL) {
            index = (index + 1) % hashmap_size;
        }
        return index;
    }

    do {
        if (hashmap[index] != NULL && *(hashmap[index]->key) == key ) {
            return index;
        }
        index = (index + 1) % hashmap_size;
    } while (index != tmp_index);

    return -1;
}

bucket *initialize_bucket_object (int *key, int *value) {
    bucket *new_bucket = malloc(sizeof(bucket));

    new_bucket->key = key;
    new_bucket->value = value;
    new_bucket->used = false;

    return new_bucket;
}

map_status_t add_to_hashmap (int *key, int *value){

    int index = int_hashing(key, hashmap_size);

    bucket *new_node = initialize_bucket_object(key, value);

    if (hashmap[index] != NULL){
        index = linear_search(index, 0);

        if (index == -1) {
            return MAP_ERROR;
        }

        hashmap[index] = new_node;
        element_count++;
        return MAP_OK;
    }

    hashmap[index] = new_node;
    element_count++;
    return MAP_OK;
}

map_status_t remove_from_hashmap (int *key) {

    int index = int_hashing(key, hashmap_size);
    index = linear_search(index, *(key));

    if (index == -1) {
        return MAP_ERROR;
    }

    free(hashmap[index]);

    hashmap[index] = NULL;
    element_count--;

    return MAP_OK;
}

map_status_t get_value(int *key, int *value){
    int index = int_hashing(key, hashmap_size);
    int index_searched_item = linear_search(index, *(key));

    if (index_searched_item == -1) {
        return MAP_ERROR;
    }

    *(value) = *(hashmap[index_searched_item]->value);

    return MAP_OK;
}

void process_error_code(map_status_t err_code) {
    switch (err_code) {
        case 0:
            printf("MAP STATUS OK\n");
            break;
        case -1:
            printf("MAP STATUS ERROR\n");
            break;
        case -2:
            printf("MAP STATUS NOT FOUND\n");
            break;
        default:
            printf("MAP STATUS OK\n");
            break;
    }
}
