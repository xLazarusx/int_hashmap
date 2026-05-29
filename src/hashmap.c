#include "hashmap.h"
#include "hash_functions.h"
#include <stdbool.h>
#include <stdlib.h>

#define HASHMAP_SIZE 23
#define REHASHING_THRESHOLD 0.7
#define max_chaining 8

typedef struct bucket_t bucket;

typedef struct bucket_t{
    int *key;
    int *value;
    _Bool used;
    bucket *next;
}bucket;

typedef struct map_t{
//    size_t chaining_size;
    bucket* hashmap_element;
}map;

static map *hashmap[HASHMAP_SIZE] = { NULL };

bucket *initialize_bucket_object (int *key, int *value) {
    bucket *new_bucket = malloc(sizeof(bucket));

    new_bucket->key = key;
    new_bucket->value = value;
    new_bucket->used = false;
    new_bucket->next = NULL;

    return new_bucket;
}

bucket *traversal_ll_last_node (int index){
    bucket *current_hashmap_element = hashmap[index]->hashmap_element;

    while (current_hashmap_element->next != NULL) {
        current_hashmap_element = current_hashmap_element->next;
    }
    return current_hashmap_element;
}

bucket *traversal_specific_node (int index, int *key, bucket **prev_node, bucket **next_node){
    bucket *current_hashmap_element = hashmap[index]->hashmap_element;

    while (current_hashmap_element->key != key){
        *prev_node = current_hashmap_element;
        current_hashmap_element = current_hashmap_element->next;
    }

    *next_node = current_hashmap_element->next;

    return current_hashmap_element;
}

map_status_t add_to_hashmap (int *key, int *value){

    int index = int_hashing(key, HASHMAP_SIZE);

    if (index < 0) {
        return MAP_INDEX_NEGATIVE;
    }

    bucket *new_node = initialize_bucket_object(key, value);

    if (hashmap[index] == NULL) {

        hashmap[index] = malloc(sizeof(map));

        if (!hashmap[index]) {
            return MAP_ERROR;
        }
//        hashmap[index]->chaining_size++;
        hashmap[index]->hashmap_element = new_node;

        return MAP_OK;
    }

    bucket *last_node = traversal_ll_last_node (index);

    last_node->next = new_node;

    return MAP_OK;
}

map_status_t remove_from_hashmap (int *key) {

    int index = int_hashing(key, HASHMAP_SIZE);

    if (index < 0) {
        return MAP_INDEX_NEGATIVE;
    }

    bucket *prev_node = NULL;
    bucket *next_node = NULL;

    bucket *searched_node = traversal_specific_node(index, key, &prev_node, &next_node);

    prev_node->next = next_node;

    free(searched_node);

    return MAP_OK;
}

int *get_value(int *key){

    int index = int_hashing(key, HASHMAP_SIZE);
    int *searched_key = key;

    bucket *current_hashmap_element = hashmap[index]->hashmap_element;

    while (current_hashmap_element->key != searched_key) {
        current_hashmap_element = current_hashmap_element->next;
    }

    return current_hashmap_element->value;
}
