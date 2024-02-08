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
// Provided below is a partition function. 
// Name:partition
// Input(s):
//  - 'arr[]' represents that is an array of integers.
//     This is the array that will be partition.
//  - 'low' is the start index of array, start from 0.
//  - 'high'is the end index of array.It's the array size - 1.
// Output: Return i,  the current index position of pivot after partition to two parts:
// left part smaller or equal to pivot, right part larger than pivot.
// This function will partition array into 2 parts, the one array includes the value that less than pivot 
// that move to left of pivot, another one array includes the value that greater than array will move 
// to the right of pivot.
int partition(int arr[], int low, int high){
    // choose the element in the end of index as pivot.
    // Use an example array = [10, 90, 50, 70], low = 0, high = 4-1.
    int pivot = arr[high];
    // initialized the i for index of smaller element,
    // to followed the element index that smaller than the pivot.
    // Example: pivot= array[4-1] = 70, i=0
    int i = low;
    // using j as index for looping the whole array until high -1,
    // beacause the array[high] is pivot now.
    for (int j = low; j < high; j++){
        // if array[j] less or equal to the pivot, then swap the element with array[i].
        if (arr[j] <= pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // Once swap the smaller element to the left of pivot, the i will increase by 1.
            // IF not greater than the pivot, i will not change.
            i++;
            // Example: 1st pass: j=0,array[0]=10 <70, swap, i+1=1,j+1
            // [10,90,50,70]
            // 2nd: i = 1, j=1,array[1]=90>70, no swap, i not change, j+1;
            // 3rd:i = 1, j=2, array[2]=50<70, swap,i+1,j+1
            // [10,50,90,70]
            // j=3,loop end, i=2
        }
    }
    // swap arr[i] and arr[high](pivot)
    // To ensure that left of pivot is smaller part, right is larger part.
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    //Example: swap arry[2]=90 and array[high]=70
    //[10,50,70,90]
    // return the current index position of the pivot,
    // then can help the left and right side of pivot quick sort.(wil used in quicksort function)
    return i;
}

// =============== quickSort Function ===============
// Provided below is a quickSort function.
// Name: quickSort
// Input(s):
//  - 'arr[]' represents that is an array of integers.
//     This is the array that to be sorted.
//  - 'low' is the start index of the array, starting from 0.
//  - 'high' is the end index of the array.It's the array size - 1.
// Output: No value return.But the two side of pivot element should be sorted.
// This function will sorted the subarray, which is come from array after partition.
// Both element from left side and right side of pivot should be sorted as ascending order. 
void quickSort(int arr[], int low, int high){
    // loop through whole array.Using low < high as condition
    // to make sure use quicksort for size 1 or 0 array that to imporve the efficiency.
    if(low<high){
        // pivot index is the current position of pivot after partition.
        int pivotIndex = partition(arr, low, high);
        // The partition divied the array into 2 subarray.
        // Sort the left part subarray of pivot.
        quickSort(arr, low, pivotIndex-1);
        // sort the right part subarray of pivot.
        quickSort(arr, pivotIndex+1, high);
    }
}

// =============== Sort Function ===============
// Provided below is a sort function. Use the following
//  format for your helper function documentation:
// Name: sortIntegers
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size  tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size) {
    // TODO: Implement quicksort here. Inside the sort choose
    //  a static pivot point, meaning
    // your pivot should always be at the same position in the array.

    // you will answer questions in the written section about how to
    // implement this sort when the pivot can change position.

    // do not edit the code in main in order to implement your sort.
    quickSort(array, 0, size-1);

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
