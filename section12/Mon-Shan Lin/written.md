1. Explain what you think the worst-case big O complexity and the best-case big O complexity of bubble sort is as implemented in our code. Give reasons for why you think that is the big O complexity for each case.

The worst-case and the best-case big O complexity of bubble sort are O(n^2) based on the code provided. There are two nested loops. The inner loop runs O(n) comparisons while the outer loop iterates O(n) times over every single number in the array. As a result, the time complexity is O(nxn), which is O(n^2)for both worst-case and the best-case. 

2. Is there a more efficient way to write bubble sort that changes the performance in the best case? If so, describe (in general terms, we don't need the exact C code) how that implementation of bubble sort would be different.

Yes, there is a more effcient way to write bubble sort that changes the performance in the best case by stopping/breaking the program when there is not swap in the inner loop. That is, in the best case, when the array is sorted and no swap is performed, the array will be run only once to compare the numbers. As a result, in the best case, the big O complexity of bubble sort becomes O(n) when the array is sorted. 

3. Explain what you think the worst-case big O complexity and the best-case big O complexity of selection sort is as you've implemented it. Why do you think that?

The worst-case and the best-case big O complexity of selection sort are both O(n^2).There are two nested loop. The inner loop runs O(n) comparisons to find the minimun number while the outer loop iterates O(n) times over every single number in the array. Even in the best case when the array is sorted, for each iteration, we still need to perform the search operation for checking to be sure that the numbers in the array are in the correct order. Therefore, the worst-case and the best-case big O complexity of selection sort are the same.

4. Does selection sort require any additional storage (i.e. did you have to allocate any extra memory to perform the sort?) beyond the original array?

No, selection sort does not require additional storage beyond the original array. The swap is performed within the original array (i.e. sorting in place) without creating any new array. As a result, the space complexity for selection sort is O(1).

5. Explain what you think big O complexity of sorting algorithm that is built into the C libraries is. Why do you think that? Do a little bit of research to try to answer this one - it's a preview of the faster sorts we'll see soon.

The C libraries uses qsort, which is its implementation of quicksort. Quicksort is a divid-and-conquer algorithm and is much faster than bubble sort and selection sort as illustrated in our sorting experiment by comparing the runtime among these sorting algorithms. Quicksort involves the following sorting algorithm. First, we pick a number from the array called pivot. Next, we partition the numbers into two sub-arrays which contain the numbers smaller and larger than the pivot and call quicksort recursively on the two sub-array. The performance of quicksort heavily depends on the pivot we choose. If we select a pivot that is always the same index in the array,not splitting the array into two halves as one array is always empty,this will give us a worst case O(n2) running time. If we randomly select a random element as the pivot, dividing the array in half every time without making many resursive calls, this will be the best case scenario. In the best case, the height of the call stack is O(logn) for n elements in each level of the stack, therefore the big O complexity is O(nlogn). In the worst case, the height of the call stack is O(n) for n elements in each level of the stack, therefore the big O complexity is O(n^2).
