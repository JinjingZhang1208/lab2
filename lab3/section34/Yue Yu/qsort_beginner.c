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

In addition, write one comment per line of code explaining how that line is helping accomplish the goals of the "partition" function. 
*/

// Name: partition
// Input(s):
//  - 'arr []' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'low' is the index of the first element in the array.
//  - 'high' is the index of the last element in the array.
// Output: No value is returned, but 'array' should be sorted.
int partition(int arr[], int low, int high) {
    /* The goal of partition: 1) choose a pivot, 2) make sure all elements less than the pivot is on its left, 3) make sure all elements greater than the pivot is on its right.
 	* To do this, we choose the last element as the pivot. The two indicies i and j are used to differentiate elements that are less than or greater than the pivot. 
 	*/

	// Choose the last element as the pivot.
    int pivot = arr[high];
    // We use index i as a divider. Any elements on and before index i will be less than the pivot (on the left of the pivot in the end). Since before the partition, we don't know any element that is less than the pivot, we place index i in a position one index before index 0 (the index of the first element in the array.)
	int i = low - 1;
	
	/* We use index j as a loop variable and another divider. As it iterates through the first to the next to last element, it excludes those elements that are less than the pivot and include those that are greater than the pivot. 
    * When the iteration finishes, any element from the beginning to index i will be less than the pivot, and any element from index i+1 to the next to last element will be greater than the pivot.
    * This is where we will swap the position of the element on index i+1 (greater than the pivot) and the pivot. After the swap, every element on the left of the pivot is less than the pivot, and every element on the right of the pivot is greater than the pivot.*/
	
	// The for loop uses j as the loop variable. It starts from the beginning of the array and stops at the next to last element of the array.
    for (int j = low; j < high; j++) {
		// If the current element (in the loop) is less than or equal to the pivot, it means they should be place at or before index i.
        if (arr[j] <= pivot) {
			// We increase index i by 1 so that we can make space for the element that is less than the pivot.
            i++;
            // We exchange arr[i] and arr[j] by using an integer temp. We use temp to store the value of arr[j].
            int temp = arr[j];
			// Now we can store the value of arr[i] at index j.
            arr[j] = arr[i];
			// We assign temp (which originally stores the value of arr[j]) to the index of i.
            arr[i] = temp;
        }
    }
    // We exchange arr[i + 1] and arr[high], in other words, the first element among the integers that are greater than the pivot is exchanged with the pivot. We use temp to store the value of arr[i + 1]. 
    int temp = arr[i + 1];
	// Now we can store the value of arr[high] (the pivot) at index i + 1.
    arr[i + 1] = arr[high];
	// Now we can store the value of temp (which originally stores the value of arr[i+1]) at index high.
    arr[high] = temp;
	// Now return the index of i + 1, which is where the pivot is at now.
    return i + 1;
}

// Name: quickSort
// Input(s):
//  - 'arr []' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'low' is the index of the first element in the array.
//  - 'high' is the index of the last element in the array.
// Output: No value is returned, but 'array' should be sorted.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
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
    quickSort(array, 0, size - 1);
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

