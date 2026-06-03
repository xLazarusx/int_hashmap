#include "hashmap.h"
#include <stdio.h>

int main(void){

    int erg;

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
    int key_11 = 142;  int value_11 = 387;
    int key_12 = 27;   int value_12 = 753;
    int key_13 = 837;  int value_13 = 199;
    int key_14 = 456;  int value_14 = 604;
    int key_15 = 93;   int value_15 = 277;
    int key_16 = 700;  int value_16 = 821;
    int key_17 = 189;  int value_17 = 100;
    int key_18 = 14;   int value_18 = 912;
    int key_19 = 799;  int value_19 = 301;
    int key_20 = 173;  int value_20 = 748;
    int key_21 = 612;  int value_21 = 556;
    int key_22 = 133;  int value_22 = 291;
    int key_23 = 117;  int value_23 = 832;
    int key_24 = 304;  int value_24 = 177;
    int key_25 = 288;  int value_25 = 443;
    int key_26 = 13;   int value_26 = 699;
    int key_27 = 251;  int value_27 = 323;
    int key_28 = 166;  int value_28 = 578;
    int key_29 = 328;  int value_29 = 645;
    int key_30 = 155;  int value_30 = 410;

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

    get_value_hashmap(&key_9, &erg);
    remove_from_hashmap(&key_1);

    add_to_hashmap(&key_11, &value_11);
    add_to_hashmap(&key_12, &value_12);
    add_to_hashmap(&key_13, &value_13);
    add_to_hashmap(&key_14, &value_14);
    add_to_hashmap(&key_15, &value_15);
    add_to_hashmap(&key_16, &value_16);
    add_to_hashmap(&key_17, &value_17);
    add_to_hashmap(&key_18, &value_18);
    add_to_hashmap(&key_19, &value_19);
    add_to_hashmap(&key_20, &value_20);
    add_to_hashmap(&key_21, &value_21);
    add_to_hashmap(&key_22, &value_22);
    add_to_hashmap(&key_23, &value_23);
    add_to_hashmap(&key_24, &value_24);
    add_to_hashmap(&key_25, &value_25);
    add_to_hashmap(&key_26, &value_26);
    add_to_hashmap(&key_27, &value_27);
    add_to_hashmap(&key_28, &value_28);
    add_to_hashmap(&key_29, &value_29);
    add_to_hashmap(&key_30, &value_30);

    map_status_t err_code = get_value_hashmap(&key_9, &erg);

    process_error_code(err_code);
    printf("Result is: %d\n", erg);

    destroy_hashmap();
    return 0;
}
