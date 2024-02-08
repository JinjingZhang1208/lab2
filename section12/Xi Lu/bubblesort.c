#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
#include <time.h> // Time functions

#ifndef EXPERIMENT
#define EXPERIMENT 0 // we will use this for Part 4 of this lab
#endif

// =============== Helper Functions ===============
void swap(int* a, int* b) {
    int temperary = *a;
    *a = *b;
    *b = temperary;
}

void printIntArray(int* array, unsigned int size) {
    // Note: 'unsigned int' is a datatype for storing positive integers.
    unsigned int i;
    for (i = 0; i < size; i = i + 1) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// =============== Sort Function ===============
void bubblesort(int* array, unsigned int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// =============== Main Functions ===============
int main(int argc, char* argv[]) {

#if EXPERIMENT == 0
    int dataset1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dataset2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int dataset3[] = {0, 3, 2, 1, 4, 7, 6, 5, 8, 9, 10};
    int dataset4[] = {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int dataset5[] = {100, 201, 52, 3223, 24, 55, 623, 75, 8523, -9, 150};
    int dataset6[] = {-1, 1, 2, -3, 4, 5, -6, 7, 8, -9, 10};

    // Sort our integer array
    bubblesort(dataset1, 11);
    bubblesort(dataset2, 11);
    bubblesort(dataset3, 11);
    bubblesort(dataset4, 11);
    bubblesort(dataset5, 11);
    bubblesort(dataset6, 11);

    // Print out an array
    printIntArray(dataset1, 11);
    printIntArray(dataset2, 11);
    printIntArray(dataset3, 11);
    printIntArray(dataset4, 11);
    printIntArray(dataset5, 11);
    printIntArray(dataset6, 11);

#else

    if (argc != 2) {
        printf("One argument expected: ./bubblesort 1000\n");
        return 1;
    }

    const int size = atoi(argv[1]);
    time_t t;
    srand((unsigned)time(&t));
    int* random = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        random[i] = rand() % size;
    }

    // You can uncomment if you'd like to see the size sorted
    // printf("Before the sort: ");
    // printIntArray(random, size);

    struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
    bubblesort(random, size);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec - begin.tv_sec);
    printf("Total time = %f seconds\n", time_taken);

    // Confirm the sort worked
    // printf("After the sort: ");
    // printIntArray(random, size);

    free(random);

#endif

    return 0;
}
