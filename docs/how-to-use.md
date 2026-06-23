# HOW TO USE

# 1. INCLUDE

- include both libariers, hash_function and hashmap, into your own C program

# 2. CREATE A HASHMAP

- There is no need for an init function, just call add_to_hashmap, if its the first call, the hashmap gets automatically allocated

# 3. HASHMAP MANAGEMENT

- to add an key-value pair to the hashmap, use add_to_hashmap(int *key, int *value) where:
    - ,int *key, is the storage pointer to the key's memory space
    - ,int *value, is the storage pointer to the value's memory space

- to remove an item from the hashmap, use remove_from_hashmap(int *key) where:
    - ,int *key, is the storage pointer to the key's memory space

- to get a value from the hashmap, use get_value_hashmap(int *key, int *value) where:
    - ,int *key, is the storage pointer to the key's memory space
    - ,int *value, is a buffer, where the found value will be saved

- to destroy a hashmap, use destroy_hashmap(void)

- to handle error codes from the hashmap libary, use process_error_code(map_status_t err_code) where:
    - ,map_status_t err_code, stands for any returned hashmap status code

# 4. ERROR CODES

- 0. MAP_DESTROY => returned when map destruction was successful, (Numeric Value= 1)
- 1. MAP_OK => returned when operation was successful, (Numeric Value = 0)
- 2. MAP_ITEM_NOT_FOUND => returned when the map item wasnt found, (Numeric Value = -1)
- 3. MAP_ERROR => returned when an error occurs while execution of the function, (Numeric Value = -2)
- 4. MAP_NOT_FOUND => returned when no map was created, make sure you called your first "add_to_hashmap", (Numeric Value = -3)
