#include "hashmap.h"
#include <stdio.h>

int main(void){

    int key_1 = 42;    int value_1 = 187;
    int key_2 = 7;     int value_2 = 53;
    int key_3 = 1337;  int value_3 = 99;
    int key_4 = 256;   int value_4 = 404;
    int key_5 = 13;    int value_5 = 777;
    int key_6 = 500;   int value_6 = 21;
    int key_7 = 89;    int value_7 = 300;
    int key_8 = 4;     int value_8 = 612;
    int key_9 = 999;   int value_9 = 1;
    int key_10 = 73;   int value_10 = 48;

    add_to_hashmap(&key_1, &value_1);
    add_to_hashmap(&key_2, &value_2);
    add_to_hashmap(&key_3, &value_3);
    add_to_hashmap(&key_4, &value_4);
    add_to_hashmap(&key_5, &value_5);
    add_to_hashmap(&key_6, &value_6);
    add_to_hashmap(&key_7, &value_7);
    add_to_hashmap(&key_8, &value_8);
    add_to_hashmap(&key_9, &value_9);
    add_to_hashmap(&key_10, &value_10);


    int *erg = get_value(&key_5);

    printf("Result is: %d\n", *erg);

    return 0;
}
