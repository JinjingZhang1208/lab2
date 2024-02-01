#include <stdio.h> // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include <time.h>   // so we can use time_t and clock_gettime()

#ifndef EXPERIMENT
#define EXPERIMENT 1 // we will use this for Part 4 of this lab
#endif

// =============== Helper Functions ===============
void swap(int* a, int* b){
    // TODO: Swap two integers in an array.
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMinimum(int* array, int start, int stop){
    int minIndex = start;
    for (int i = start + 1; i < stop; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex; // TODO: Modify this to return the
}

void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0 ; i < size ; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

// =============== Sort Function ===============
void sortIntegers(int* array, unsigned int size){
    for (int i = 0; i < size; i++) {
        int minIndex = findMinimum(array, i, size);
        swap(&array[i], &array[minIndex]);
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
  
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);

#else

  if (argc != 2) {
    printf("One argument expected: ./selection 1000\n");
    return 1;
  }

  const int size = atoi(argv[1]);
  time_t t;
  srand((unsigned)time(&t));
  int* random = (int*)malloc(sizeof(int)*size);

  for(int i = 0 ; i < size ; i++) {
    random[i] = rand()%size; 
  }

  // printIntArray(random, size);

  struct timespec begin, end;
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  sortIntegers(random,size);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
            (end.tv_sec  - begin.tv_sec);
  printf ("Total time = %f seconds\n", time_taken);

  
  free(random);

#endif

  return 0;
}
