# Explain what you think the worst-case big O complexity and the best-case big O complexity of bubble sort is as implemented in our code. Give reasons for why you think that is the big O complexity for each case.

==========================================================================================
The worst-case is when the input of array is completely reversed, that means to get ascend or descend will need to run
the whole list, each round of comparison needs to move an element to the end of the array, will be n*(n-1)/2 O(n2).
The best situation like dataset2, the input array is already in completely orderd, the complexity will be O(n).

# Is there a more efficient way to write bubble sort that changes the performance in the best case? If so, describe (in general terms, we don't need the exact C code) how that implementation of bubble sort would be different.

==========================================================================================
I do not know the answer but after I do some google search, I found there is a way called "Adaptive Bubble Sort”".
Bascially it means The Adaptive Bubble Sort adds a flag to check if any swaps have occurred in each pass. If no swaps occurred during a pass, it means the list is already sorted, and the algorithm can terminate early. 

https://www.quora.com/What-are-adaptive-and-non-adaptive-sorting-algorithms


# Explain what you think the worst-case big O complexity and the best-case big O complexity of selection sort is as you've implemented it. Why do you think that?

==========================================================================================

I think for selection sort the worst and the best are equally complex, since to make swap you have to scan the whole 
list so no matter what is the order ascend or descend. You still need to scan the whole list because you can pre-know 
the number.

# Does selection sort require any additional storage (i.e. did you have to allocate any extra memory to perform the sort?) beyond the original array?
==========================================================================================

Selection Sort sorts in-place, meaning we do not need to allocate any memory for the sort to occur.

https://medium.com/@mariam.jaludi/sorting-algorithms-selection-sort-66c3fc8278b9

# Explain what you think big O complexity of sorting algorithm that is built into the C libraries is. Why do you think that? Do a little bit of research to try to answer this one - it's a preview of the faster sorts we'll see soon.
==========================================================================================

To get fast computing result, that is the only reason i can think of.

