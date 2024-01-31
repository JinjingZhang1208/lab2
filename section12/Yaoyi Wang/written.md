# Discussion exercises

1.Explain what you think the worst-case big O complexity and the best-case big O complexity of bubble sort is as implemented in our code. Give reasons for why you think that is the big O complexity for each case.

- I think the worst-case big O complexity is O(n^2). This worst-case occurs when the array is sorted in reverse order, which means each element has to be compared and swapped with every other element in the array. The total number of comparison is '(n-1) + (n-2) + ... + 1', which is the sum of the first 'n-1' natural numbers, leading to a total of 'n(n-1)/2' comparisons and swaps in the worst case.
- The best-case big O complexity is also 0(n^2). This best-case occurs when the array is sorted. Even it's sorted, the implementation of bubble sort does not recognize the sorted array in its first pass. It compares each pair of adjacent elements to check if they are in the correct order. Although no swaps are needed, the number of comparisons remains the same. Therefore, the best-case complexity is O(n^2).


2.Is there a more efficient way to write bubble sort that changes the performance in the best case? If so, describe (in general terms, we don't need the exact C code) how that implementation of bubble sort would be different. 
- The optimized bubble sort can be added an additional flag to check whether any swaps have been made during an iteration. If no swaps are made, the algorithmcan terminate early, recognizing that the list is sorted. This optimization improves the best-case complexity to'O(n)', that is when the list is already sorted.


3.Explain what you think the worst-case big O complexity and the best-case big O complexity of selection sort is as you've implemented it. Why do you think that?
- The worst-case big O complexity and the best-case big 0 complexity of selection sort are O(n^2). The worst-case occurs when the array is in reverse order. Selection sort works by finding the minimum element from the unsorted part of the array and swapping it with the first unsorted element in each iteration. For an array of size 'n', the total number of comparisons is (n-1) + (n-2) + ... + 1, which is the sum of the first n-1 natural numbers. This results in a total of n(n-1)/2 comparisons, simplifying to O(n^2). Even if the array is sorted, the algorithm does not know this in advance and cannot skip any steps. Thus, the best-case time complexity remains O(n^2).


4.Does selection sort require any additional storage (i.e. did you have to allocate any extra memory to perform the sort?) beyond the original array?
- Selection sort is an in-place sorting algorithm that does not require additional memory beyond the original array. It sorts the array by repeatedly finding the minimum element from the unsorted part and swapping it with the beginning of the unsorted part, all within the original array. 


5.Explain what you think big O complexity of sorting algorithm that is built into the C libraries is. Why do you think that? Do a little bit of research to try to answer this one - it's a preview of the faster sorts we'll see soon. 
- I think it is O(n log n). It splits the problem into smaller parts, sorts each part, and then combines them. It does so by choosing a pivot element and arranging all others around it, so smaller ones are on one side and larger on the other. This process is repeated recursively on the smaller sub-parts. It looks at every item in the list (which is the n part of n log n), and it does this dividing and sorting process about log n times (because each time, it cuts the problem in half, which is much quicker than doing it one by one). So, the total effort is like doing a task n times in log n rounds, which is why its complexity is O(n log n). 
