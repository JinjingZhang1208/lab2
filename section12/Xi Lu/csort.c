// Compile with: clang -g csort.c -o csort
// Run with: ./csort

// C-Standard Libraries
#include <stdio.h> // Include file for standard input/output
#include <stdlib.h>
#include <time.h> // Time functions

#ifndef EXPERIMENT
#define EXPERIMENT 1 // we will use this for Part 4 of this lab
#endif

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//          
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

// Name:    printIntArray
// Desc:    Prints out an integer array
// param(1):A pointer to an array (i.e. the array 
//          itself points to the first index)
// param(2) The size of the array (Because we do 
//          not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
    // Note: 'unsigned int' is a datatype for storing positive integers.
    unsigned int i;
    for(i = 0; i < size; i=i+1){
        printf("%d ",array[i]);
    }
    printf("\n");
}
// =============== Selection Sort Functions ===============
void swap(int* a, int* b) {
    // Swap two integers in an array
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMinimum(int* array, int start, int size) {
    // Finds at which index in an array the minimum value is found
    int min_index = start;
    for (int i = start + 1; i < size; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void sortIntegers(int* array, unsigned int size) {
    // Perform the actual selection sort
    for (unsigned int i = 0; i < size - 1; i++) {
        int min_index = findMinimum(array, i, size);
        swap(&array[min_index], &array[i]);
    }
}

// =============== Main Functions ===============
int main(int argc, char* argv[]){

#if EXPERIMENT==0
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array with selection sort
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
    printf("One argument expected: ./csort 1000\n");
    return 1;
  }

  // Convert the argument of the program into an integer
  const int size = atoi(argv[1]);
  // Generate a random seed
  time_t t;
  srand((unsigned)time(&t));
  // Allocate memory
  int* random = (int*)malloc(sizeof(int)*size);

  // Populate our test data set
  for(int i = 0 ; i < size ; i++) {
    // Generate random values from 0 to 99
    random[i] = rand()%size; 
  }

  // You can uncomment if you'd like to see the size sorted
  // printf("Before the sort: ");
  // printIntArray(random, size);

  // Setup timers  
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Perform the sort with selection sort
  sortIntegers(random, size);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
            (end.tv_sec  - begin.tv_sec);
  printf ("Total time = %f seconds\n", time_taken);

  // Confirm the sort worked
  // printf("After the sort: ");
  // printIntArray(random, size);
  
  // Free our random array
  free(random);

#endif

  return 0;
}
