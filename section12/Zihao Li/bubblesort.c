// Compile with: clang -g bubblesort.c -o bubblesort
// Run with: ./bubblesort

// C-Standard Libraries
#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
#include <time.h> // Time functions

#ifndef EXPERIMENT
#define EXPERIMENT 0 // we will use this for Part 4 of this lab
#endif

// =============== Helper Functions ===============
// Swaps two numbers in an array
// Input: The 'address of' an index into an array for positions in an array.
void swap(int* a, int* b) {
    int temp = *a; // Store the value at address a in a temporary variable
    *a = *b;       // Assign the value at address b to the location of a
    *b = temp;     // Assign the value stored in the temporary variable to the location of b
}

// Name:    printIntArray
// Desc:    Prints out an integer array
// param(1):A pointer to an array (i.e. the array
//          itself points to the first index)
// param(2) The size of the array (Because we do
//          not know how big the array is automatically)
void printIntArray(int* array, unsigned int size) {
    // Note: 'unsigned int' is a datatype for storing positive integers.
    unsigned int i;
    for (i = 0; i < size; i = i + 1) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubblesort(int* array, unsigned int size) {
    // Iterate through the array multiple times
    for (int i = 0; i < size - 1; i++) {
        // Within each iteration, iterate through the array again to compare adjacent elements
        // This inner loop performs the core logic of the bubble sort algorithm
        // It compares adjacent elements and swaps them if they are out of order
        // After each iteration of the outer loop, the largest unsorted element 'bubbles up' to its correct position
        // As a result, subsequent iterations of the outer loop can ignore the sorted portion of the array
        for (int j = 0; j < size - 1; j++) {
            // Compare the current element with the next element
            // If the current element is greater than the next element, they are out of order
            if (array[j] > array[j + 1]) {
                // Swap the current element with the next element to correct the order
                swap(&array[j], &array[j + 1]); // Swap the current element with the next element if they are out of order
            }
        }
    }
}

// =============== Main Functions ===============
int main(int argc, char* argv[]) {

#if EXPERIMENT == 0
    // Some test data sets.
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

    // Convert the argument of the program into an integer
    const int size = atoi(argv[1]);
    // Generate a random seed
    time_t t;
    srand((unsigned)time(&t));
    // Allocate memory
    int* random = (int*)malloc(sizeof(int) * size);

    // Populate our test data set
    for (int i = 0; i < size; i++) {
        // Generate random values from 0 to 99
        random[i] = rand() % size;
    }

    // You can uncomment if you'd like to see the size sorted
    // printf("Before the sort: ");
    // printIntArray(random, size);

    // Setup timers
    struct timespec begin, end;
    // Get the time before we start
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
    // Perform the sort
    bubblesort(random, size);
    // Get the time after we are done
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec - begin.tv_sec);
    printf("Total time = %f seconds\n", time_taken);

    // Confirm the sort worked
    // printf("After the sort: ");
    // printIntArray(random, size);

    // Free our random array
    free(random);

#endif

    return 0;
}
