
### 1. Bubble Sort big O complexity

In our code, a nested for loop is employed. Assuming the array size is denoted as N, the outer loop iterates N-1 times in any case, and the inner loop performs N-1 comparisons (and swaps if necessary) during each iteration.

Assuming a constant number of executions for comparisons and swaps, denoted as C, the total executions in bubble sort for an N-sized array can be expressed as **C * (N-1) * (N-1)**. Consequently, the overall big O complexity is **O($N^2$)**.

### 2. How to improve bubble sort in the best case?

For one thing, we can modify the inner loop to iterate end at `size - i - 1`.
This improvement is based on the fact that after i times iterations, the last `i` elements in the array are already sorted. Hence, there is no need to compare them in the inner loop.

For another, we can stop the sorting process once no swaps occur in an iteration.
By adding this improvement, bubble sort can terminate early in the best-case scenario, where the array is already sorted. 
If no swaps are made in an iteration, the algorithm concludes that the array is sorted. This leads to the best-case time complexity of O(1), as only one iteration is needed when the array is in the right order.

### 3. Selection Sort big O complexity.

The worst-case and best-case big O complexities of selection sort are both **O($N^2$)**.

Assuminging the size of the array is denoted as N, in each scenario, the outer loop performs (N - 1) rounds and call the fucntion to find the smallest number in each round.
In the $i^{th}$ round of finding the smallest number, the size of the target array is reduced to (N - 1 - i).
Consequently, the total number of iterations can be expressed as the sum of integers from (N-1) to 1, which equals N(N-1)/2 or 0.5($N^2$ - N). This results in a big O complexity of **O($N^2$)** for both the worst and best cases.

### 4. Does Selection Sort require additional storage?

No.
All the swapping operations happen within the existing array, and there is no need for  a new array to store the temporary values.

### 5. Big O complexity of built-in csort.

I think the big O complexity of sorting algorithm that built into the C libraries is O(NlogN).
Because, in my experinment, I found that when the array size(N) expands by a factor of 10, the runtime of csort also increases by factor of about 10 or more.
This observation led me to condiser possible big O tiem complexities such as Therefore, the possible big O time complexity might be O(N) or O(NlogN). And after doing some search online, I found O(NlogN) is the correct answer.
Therefore, the big O complexity of built-in csort is O(NlogN), which matches with theory and practice.

