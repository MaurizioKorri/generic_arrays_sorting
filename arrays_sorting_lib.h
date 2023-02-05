#ifndef ARRAYS_SORTING_LIB_H_laokjsdnjduehfuanfw
#define ARRAYS_SORTING_LIB_H_laokjsdnjduehfuanfw

#include <stdlib.h>

//################################DECLARATION OF FUNCTIONS######################################################################*/


/*
 * Binary insertion sort is a sorting algorithm that is similar to insertion sort, but it uses a binary search to 
 * find the correct position where to put each element into the sorted portion of the array. This can make it more efficient 
 * than insertion sort, especially for larger arrays.
 * It accepts as input a pointer to function implementing the comparison relation between the elements of the array. 
 * Such function should accept as inputs two pointers to elements and return 0 if the elements are equal, a positive value
 * if the first element precedes the second, and a negative value otherwise. The input parameter cannot be NULL.  
*/
void binary_insertion_sort(void* array_pointer, long array_size, size_t bit_size, int (*compare)(void*,void*));


/*
 * Quick sort is a sorting algorithm that works by selecting a pivot element from the array
 * and partitioning the other elements around it. The pivot element is then placed
 * in its correct position in the sorted array, and the process is repeated recursively on the left and right halves of the array until it is fully sorted. 
 * It accepts as input a pointer to function implementing the comparison relation between the elements of the array. 
 * Such function should accept as inputs two pointers to elements and return 0 if the elements are equal, a positive value
 * if the first element precedes the second, and a negative value otherwise. The input parameter cannot be NULL.  
 * 
*/
void quick_sort(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*));

#endif /*ARRAYS_SORTING_LIB_H_laokjsdnjduehfuanfw*/