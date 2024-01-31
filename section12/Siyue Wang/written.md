1. Explain what you think the worst-case big O complexity and the best-case big O complexity of bubble sort is as implemented in our code. Give reasons for why you think that is the big O complexity for each case.
The worst case is when the list is reversed and the time complexity is O(n^2), whereas the best case is when the list is already sorted, and it is either O(n^2), or O(n), as explained in the next question. The default implementation is O(n^2). For the outer loop, we need to iterate over the entire list and for the inner loop, it is also approximately the same iterations. After multiplying these two together, the complexity is O(n^2).

(I personally think of the complexity in terms of comparisons and swaps. Every two element in the list needs to be compared, which is randomly choosing two. According to permutation, it is  n(n-1)/2, which is O(n^2), and complexity for swaps are 1, so the total complexity is O(n^2), which also explains why time complexity is the same for bubble sort, insertion sort and selection sort: because every element needs to be compared. I am not sure my understanding is correct.)

2. Is there a more efficient way to write bubble sort that changes the performance in the best case? If so, describe (in general terms, we don't need the exact C code) how that implementation of bubble sort would be different. 
The optimal way to do bubble sort, as we mentioned in class, would be to stop when there are no swaps. In the best case, the complexity is O(n), because we would only iterate over the outer loop and quit the function. 


3. Explain what you think the worst-case big O complexity and the best-case big O complexity of selection sort is as you've implemented it. Why do you think that?
The worst case and the best case are all O(n^2). Because we need to loop through the outer loop and the inner loop every time. 


4. Does selection sort require any additional storage (i.e. did you have to allocate any extra memory to perform the sort?) beyond the original array?
No. In the algorithm I coded, I only moved pointers and never copied the array to create another one. 


5. Explain what you think big O complexity of sorting algorithm that is built into the C libraries is. Why do you think that? Do a little bit of research to try to answer this one - it's a preview of the faster sorts we'll see soon.
According to this website (https://www.geeksforgeeks.org/c-qsort-vs-c-sort/), csort uses quicksort. 

