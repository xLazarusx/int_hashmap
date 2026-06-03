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
}bucket;

static int hashmap_size = INITIAL_HASHMAP_SIZE;
static int element_count;
static bucket **hashmap;

int linear_search_free_slot(int index) {

    int tmp_index = index;

    do {
        if (hashmap[index] == NULL) {
            return index;
        }

        tmp_index = (tmp_index + 1) % hashmap_size;

    } while (tmp_index != index);

    return -1;
}

int linear_search_key (int index, int key) {

    int tmp_index = index;

    do {
        if (hashmap[tmp_index] != NULL && *(hashmap[tmp_index]->key) == key ) {
            return tmp_index;
        }
        tmp_index = (tmp_index + 1) % hashmap_size;
    } while (index != tmp_index);

    return -1;
}

int is_prime (int n) {
    if (n < 2) return 0;
    for (int index=2; index * index <= n; index++) {
        if (n % index == 0) return 0;
    }
    return 1;
}

int next_prime (int n) {
    while (!is_prime(n)){
        n++;
    }
    return n;
}

map_status_t map_rehashing(void) {

    if (hashmap == NULL) {
        return MAP_NOT_FOUND;
    }

    if (hashmap_size < INITIAL_HASHMAP_SIZE) {
        hashmap_size = INITIAL_HASHMAP_SIZE;
        return MAP_ERROR;
    }

    int old_hashmap_size = hashmap_size;
    hashmap_size = next_prime(hashmap_size * 2);

    bucket **tmp_hashmap = calloc(hashmap_size, sizeof(bucket));

    for (int index = 0; index < old_hashmap_size; index++) {
        if (hashmap[index] != NULL) {
            int new_index = int_hashing(hashmap[index]->key, hashmap_size);
            tmp_hashmap[new_index] = hashmap[index];
        }
        continue;
    }

    free(hashmap);
    hashmap = tmp_hashmap;

    return MAP_OK;
}

bucket *initialize_bucket_object (int *key, int *value) {
    bucket *new_bucket = malloc(sizeof(bucket));

    new_bucket->key = key;
    new_bucket->value = value;

    return new_bucket;
}

map_status_t add_to_hashmap (int *key, int *value){

    if (hashmap == NULL) {
        hashmap = calloc(hashmap_size, sizeof(bucket));
        if (!hashmap) {
            return MAP_ERROR;
        }
    }

    if ((float)element_count/hashmap_size > REHASHING_THRESHOLD) {
        map_status_t err_code = map_rehashing();

        if (err_code != MAP_OK) {
            printf("REHASHING ERROR OCCURED, ERROR CODE(map_status_t): %d\n", err_code);
        }
    }

    int index = int_hashing(key, hashmap_size);

    bucket *new_node = initialize_bucket_object(key, value);

    if (hashmap[index] != NULL){
        index = linear_search_free_slot(index);

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

    if (hashmap == NULL) {
        return MAP_NOT_FOUND;
    }

    int index = int_hashing(key, hashmap_size);
    index = linear_search_key(index, *(key));

    if (index == -1) {
        return MAP_ERROR;
    }

    free(hashmap[index]);

    hashmap[index] = NULL;
    element_count--;

    return MAP_OK;
}

map_status_t get_value_hashmap(int *key, int *value) {

    if (hashmap == NULL) {
        return MAP_NOT_FOUND;
    }

    int index = int_hashing(key, hashmap_size);
    int index_searched_item = linear_search_key(index, *(key));

    if (index_searched_item == -1) {
        return MAP_ERROR;
    }

    *(value) = *(hashmap[index_searched_item]->value);

    return MAP_OK;
}

map_status_t destroy_hashmap(void) {

    if (hashmap == NULL) {
        return MAP_NOT_FOUND;
    }

    for (int index = 0; index < hashmap_size; index++) {
        if (hashmap[index] != NULL) {
            free(hashmap[index]);
            hashmap[index] = NULL;
        }
    }

    free(hashmap);
    hashmap = NULL;

    return MAP_DESTROY_SUC;
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
        case -3:
            printf("MAP SUCCESSFULL DESTROYED");
            break;
        default:
            printf("MAP STATUS OK\n");
            break;
    }
}
