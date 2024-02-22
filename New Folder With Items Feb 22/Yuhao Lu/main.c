// compile this file with gcc -Wall main.c my_hashmap.c -o main
#include <stdio.h>
#include "my_hashmap.h"

int unitTest1() {
    // Create our hashmap
    hashmap_t* myStocks = hashmap_create(5);
    // Insert a first key/value pair
    hashmap_insert(myStocks, "RY", 93);
    // Does hashmap contain key?
    printf("RY was added should be 1: %d\n", hashmap_hasKey(myStocks, "RY"));
    // Print out the keys
    hashmap_printKeys(myStocks);
    // Retrieve RYs value
    printf("RY's value is %d\n", hashmap_getValue(myStocks, "RY"));
    // Remove a key
    hashmap_removeKey(myStocks, "RY");
    // Does hashmap contain key?
    printf("have you implemented hashmap_removeKey?\n");
    printf("RY was removed should be 0: %d\n", hashmap_hasKey(myStocks, "RY"));
    // Finally terminate our hashmap
    hashmap_delete(myStocks);
    return 1;
}

int unitTest2() {
    // Create our hashmap
    hashmap_t* myStocks = hashmap_create(5);
    // Insert a first key/value pair
    hashmap_insert(myStocks, "RY", 93);
    hashmap_insert(myStocks, "TD", 80);
    hashmap_insert(myStocks, "CNR", 154);
    hashmap_insert(myStocks, "ENB", 38);
    hashmap_insert(myStocks, "SHOP", 62);
    hashmap_insert(myStocks, "CP", 76);
    hashmap_insert(myStocks, "CNQ", 75);
    hashmap_insert(myStocks, "BMO", 116);
    hashmap_insert(myStocks, "BNS", 66);
    hashmap_insert(myStocks, "TRI", 112);
    // Print the keys
    hashmap_printKeys(myStocks);
    // Finally terminate our hashmap
    hashmap_delete(myStocks);
    return 1;
}

int unitTest3() {
    // Create our hashmap
    hashmap_t* myStocks = hashmap_create(10); // Using 10 buckets for demonstration

    // Insert several similar stock symbols to test the hash function's collision handling
    hashmap_insert(myStocks, "GOOG", 2200);
    hashmap_insert(myStocks, "APPLE", 2201);
    hashmap_insert(myStocks, "MSMF", 2202);
    hashmap_insert(myStocks, "SPACEX", 2203);
    hashmap_insert(myStocks, "TESLA", 2204);

    // Check if a specific key was added, print, retrieve its value, and then remove it
    char* testKey = "GOOG";
    printf("%s was added should be 1: %d\n", testKey, hashmap_hasKey(myStocks, testKey));
    hashmap_printKeys(myStocks);
    printf("%s's value is %d\n", testKey, hashmap_getValue(myStocks, testKey));
    hashmap_removeKey(myStocks, testKey);
    printf("%s was removed should be 0: %d\n", testKey, hashmap_hasKey(myStocks, testKey));

    // Check another key to ensure the hash function distributes keys well
    testKey = "TESLA";
    printf("%s was added should be 1: %d\n", testKey, hashmap_hasKey(myStocks, testKey));
    printf("%s's value is %d\n", testKey, hashmap_getValue(myStocks, testKey));
    hashmap_removeKey(myStocks, testKey);
    printf("%s was removed should be 0: %d\n", testKey, hashmap_hasKey(myStocks, testKey));

    // Finally terminate our hashmap
    hashmap_delete(myStocks);

    return 1;
}


int main() {

    printf("============ unitTest1() ================\n");
    unitTest1();
    printf("============ unitTest2() ================\n");
    unitTest2();
    printf("============ unitTest3() ================\n");
    unitTest3();


    return 0;
}
