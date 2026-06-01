#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

typedef enum {
    MAP_OK = 0,
    MAP_ERROR = -1,
    MAP_NOT_FOUND = -2,
}map_status_t;

map_status_t add_to_hashmap(int *key, int *value);
map_status_t remove_from_hashmap(int *key);
map_status_t get_value(int *key, int *value);
void process_error_code(map_status_t err_code);

#endif
