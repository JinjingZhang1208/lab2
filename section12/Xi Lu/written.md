1. The worst-case big O complexity of bubble sort in the provided code: O(n^2). It happens when the array is in a reverse order.
The best-case big O complexity of bubble sort in the provided code: O(n^2). Even if the array is already sorted, the algorithm still performs the same number of comparisons.
2. A more efficient way to write bubble sort that can improve the best case complexity to O(n). It involves adding a flag to check if any swaps are made in the current pass. If there is no swap, the array is already sorted, and the algorithm is terminated. It can reduce the complexity to linear.
3. The worst case big o complexity of selection sort: O(n^2). It happens because  for each element, the algorithm searches the rest of the list to find the minimum value. 
The best-case big o complexity of selection sort: O(n^2)
4. Selection sort requires additional storage beyond the original array? Selection sort does not require additional storage beyond the original array. Because selection sort rearranges the numbers within the array itself without requiring additional space for another array.
5. qsort is commonly implemented using the quick sort algorithm. Quick sort is more efficient than simple comparison-based sorting algorithms such as bubble sort and selection sort.
Worst-case complexity: O(n^2). It occurs when pivot selection is poor.
Best-case complexity: O(nlogn). It occurs with balanced partitions.
Quick sort offers better performance than simple algorithm, especially for larger datasets, due to its efficient partitioning and depth-first recursion strategy.