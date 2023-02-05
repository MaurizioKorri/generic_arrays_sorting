# generic_arrays_sorting
A small library with two sorting algorithms implementation in C.

Both algorithms accept generic types of arrays and a pointer to a compare function is needed as parameter when calling the sorting functions to compare the various elements of the arrays. 

_______________________________________________________

The library offers two sorting algorithms: 
- Binary Insertion Sort

  BIS is a quicker version of Insertion Sort that uses Binary Search to find the location where to insert an element. This way we reduce 
  complexity of the insertion from O(n) to O(log n).
 
Time complexity: 
  1. Worst case: O(N^2)
  2. Average Case: Θ(N^2)
  3. Best Case: Ω(N log N)
  
  Space complexity: 
  1. O(log N)
 
_____________________________________________________________

- Quick Sort

  Quick Sort is a Divide and Conquer algorithm, it works by selecting an element of the array which we will call pivot and partitioning the other elements into
  two partitions, one with elements less than the pivot, and the other with elements greater than the pivot. Then Quick Sort is then performed recursively on the two subarrays.
  
Time complexity: 
  1. Worst case: O(N^2)
  2. Average Case: O(N log N)
  3. Best Case: O(N log N)
  
  Space complexity: 
  1. O(log N)
  
______________________________________________________________
Unit tests are also provided for the two sorting algorithms using the unit test library Unity: https://github.com/ThrowTheSwitch/Unity

A simple usage example is provided in the sorting_usage_main.c file. 



