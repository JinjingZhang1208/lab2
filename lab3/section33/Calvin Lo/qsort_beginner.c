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

/* Put your helper function(s) in this section. 
    
You may NOT write a swap function.
In addition, inside your function(s) here, 
    do not swap values in the array using the * operator (e.g. *a = *b).
  Instead, swap values using [] array notation.
    
Document your helper function(s) in the same style as
    the "sortIntegers" function below

Your partition function should go here. Don't forget to add a docstring.

In addition, write one comment per line of code explaining how that line is
  helping accomplish the goals of the "partition" function. 
*/

// =============== Partition Function ===============
// This function chooses the last element of the array to be the pivot and uses the value of the pivot
// to partition the array into portions that are smaller than or larger than the pivot value. The pivot
// value is then put into the position after the subarray of smaller elements and before the subarray of
// larger elements. Finally, the pivot index is returned.
// Name: partition
// Input(s):
//  - 'arr' is the int array to be sorted.
//  - 'low' is the starting index of the subarray to be sorted. We use this to sort the array in place.
//  - 'high' is the end index of the subarray to be sorted. We use this to sort the array in place.
// Output: This function returns the index of the pivot in arr.
int partition(int arr[], int low, int high) {
        int pivot = arr[high]; // set the last element as the pivot
        // initialize index i
        // index i is used to track the end of the subarray of elements less than the pivot
        int i = low - 1;

        // declare index j and a temporary variable for holding values for swaps
        int j, temp;

        // index j is initialized at low to start comparisons at the beginning of the subarray to be sorted
        // this for loop is for comparing each element to the pivot
        for (j = low; j < high; j++) {
                // swaps the current element at j into the subarray of elements <= the pivot indexed by i
                // this swap also moves an element from the subarray of elements > the pivot to the right
                if (arr[j] <= pivot) {
                        i += 1; // index is incremented to provide room for the new element in the subarray
                        temp = arr[i]; // temp variable for holding one element during the swap
                        arr[i] = arr[j];
                        arr[j] = temp;
                }
        }
        // after the elements have been partitioned, swap the pivot into the next position after the subarray
        // of elements <= the pivot
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1; // return the pivot index
}

// =============== Quick Sort Function ===============
// This function is an implementation of quick sort. It partitions the array, and calls quick sort recursively
// to sort the two partitions.
// Name: quickSort
// Input(s):
//  - 'arr' is the int array to be sorted.
//  - 'low' is the starting index of the subarray to be sorted. We use this to sort the array in place.
//  - 'high' is the end index of the subarray to be sorted. We use this to sort the array in place.
// Output: There is no return. This function sorts the array in place.
void quickSort(int arr[], int low, int high){
        // this condition sets the base case for the recursion
        // the base case occurs when low is equal to high (i.e., there is only 1 element in the array)
        if (low < high) {
                int pivot = partition(arr, low, high); // get the pivot index and partition the array based on the pivot
                quickSort(arr, low, pivot - 1); // sort the subarray of elements less than or equal to the index
                quickSort(arr, pivot + 1, high); // sort the subarray of elements greater than the index
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
    // TODO: Implement quicksort here. Inside the sort choose
    //  a static pivot point, meaning
    // your pivot should always be at the same position in the array.

    // you will answer questions in the written section about how to
    // implement this sort when the pivot can change position.

    // do not edit the code in main in order to implement your sort.
    quickSort(array, 0, size - 1); // we subtract 1 from size because the high parameter is the index of the last element in the array
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
