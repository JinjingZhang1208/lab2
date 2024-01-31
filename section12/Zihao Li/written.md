1. Worst-case O(n^2):
In the worst-case scenario, bubble sort compares and swaps adjacent elements until the entire array is sorted. This means that for 
n elements, it may require n passes over the array, each time comparing and swapping adjacent elements. Therefore, the worst-case time complexity is quadratic, as it scales proportionally to the square of the number of elements.
Best-case O(n):
The best-case scenario occurs when the array is already sorted. In this case, bubble sort makes a single pass over the array to check if any swaps are needed. Since no swaps are required, the algorithm terminates early after the first pass. Therefore, the best-case time complexity is linear, as it scales proportionally to the number of elements in the array.

2. there is a more efficient way to write bubble sort that improves the performance in the best case. One optimization is to introduce a flag to track whether any swaps occurred during a pass. If no swaps occur in a pass, it means the array is already sorted, and the algorithm can terminate early. This optimization reduces the number of comparisons and swaps in the best-case scenario, improving the overall performance.

3. worst case O(n^2):
Selection sort always makes
n passes, finding the minimum
element each time, even if the array is sorted.

Best case O(n^2):
Even if the array is sorted, selection sort still makes 
n passes to confirm the minimum element in each pass.

4. No extra storage is needed as selection sort operates directly on the original array.

5. Standard sorting algorithms in C libraries usually have a time complexity of O(nlogn⁡)
O(nlogn) because they use more efficient algorithms like quicksort or mergesort,
 which perform well in a variety of scenarios.
