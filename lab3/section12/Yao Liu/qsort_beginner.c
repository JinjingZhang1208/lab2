// Compile with: clang -g qsort_beginner.c -o qsortb
// Run with: ./qsortb

#include <stdio.h> // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()

#ifndef EXPERIMENT
#define EXPERIMENT 0 // we will use this for the complexity experiments
#endif

// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size) {
    unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// =============== Helper Functions ===============

//Divide the interval based on the right endpoint.
// Name: partition
// Input: -arr A pointer to an array.
//        -low left endpoint of sorting range.
//        -high right endpoint of sorting range.
int partition(int arr[], int low, int high) {
    //Use the number at the end of the interval as the base number
    int x = arr[high];
    //i represents the subscript of the last current number that is smaller than the base number.
    int i = low - 1;
    int j, tmp;
    //Iterate through all numbers in the range
    for (j = low; j < high; j++) {
        //Determine whether the number is not greater than the base number
        if (arr[j] <= x) {
            //When it is less than the base number, i plus one represents the position where the number should be inserted.
            //Then swap the two numbers
            i = i + 1;
            if (i != j)  {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    //Swap the base number with the number subscripted i+1
    //After the exchange, the numbers on the left side of i+1 are not greater than the base number,
    //and the numbers on the right side are all greater than the base number.
    if (i + 1 != high) {
        tmp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = tmp;
    }
    return i + 1;
}

//Sort array use quick sort algorithm
// Name: quickSort
// Input: -arr A pointer to an array.
//        -low left endpoint of sorting range.
//        -high right endpoint of sorting range.
void quickSort(int arr[], int low, int high) {
    //Only operate when the sorting interval is legal
    if (low < high) {
        //Call the partition function to divide
        int pos = partition(arr, low, high);
        //Sort the intervals on the left and the intervals on the right according to the division position.
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}

// =============== Sort Function ===============
// Provided below is a sort function. Use the following
//  format for your helper function documentation:
// Name: sortIntegers
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size) {
    quickSort(array, 0, size - 1);
}

// =============== Main Functions ===============
int main(int argc, char* argv[]) {

#if EXPERIMENT == 0
    // Some test data sets.
    int dataset1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int dataset2[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int dataset3[] = { 0, 3, 2, 1, 4, 7, 6, 5, 8, 9, 10 };
    int dataset4[] = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int dataset5[] = { 100, 201, 52, 3223, 24, 55, 623, 75, 8523, -9, 150 };
    int dataset6[] = { -1, 1, 2, -3, 4, 5, -6, 7, 8, -9, 10 };

    // Sort our integer array
    sortIntegers(dataset1, 11);
    sortIntegers(dataset2, 11);
    sortIntegers(dataset3, 11);
    sortIntegers(dataset4, 11);
    sortIntegers(dataset5, 11);
    sortIntegers(dataset6, 11);

    // Print out an array
    printIntArray(dataset1, 11);
    printIntArray(dataset2, 11);
    printIntArray(dataset3, 11);
    printIntArray(dataset4, 11);
    printIntArray(dataset5, 11);
    printIntArray(dataset6, 11);

#else

    if (argc != 2) {
        printf("One argument expected: ./qsort_beginner 1000\n");
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
    sortIntegers(random, size);
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

