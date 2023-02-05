#include "arrays_sorting_lib.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
//################################DECLARATION OF INTERNAL FUNCTIONS###################################################################*/
static void swap(void *a, void *b, size_t size);

static long binary_search(void* array_pointer, void* key, long low, long high, size_t byte_size, int (*compare)(void*,void*));

static long partition_left_pivot(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*));
static long partition_right_pivot(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*));
static long partition_random_pivot(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*));
//################################IMPLEMENTATION OF FUNCTIONS########################################################################*/

//function that swaps the content of two void pointers.
static void swap(void *a, void *b, size_t size) {
    unsigned char *pa = (unsigned char *)a;
    unsigned char *pb = (unsigned char *)b;
    while (size-- > 0) {
        unsigned char c = *pa;
        *pa++ = *pb;
        *pb++ = c;
    }
}

//function that returns the index where the element will be inserted by performing a binary search on the ordered part of the array.
static long binary_search(void* array_pointer, void* key, long low, long high, size_t byte_size, int (*compare)(void*,void*)){
    
    while(low<=high){

        long mid = low + (high - low) / 2;
        int compare_result = compare(key, (array_pointer+(mid*byte_size)));

        if(compare_result==0){
            return mid;             
        }
        else if(compare_result>0){
            low = mid + 1;
        }
        else{//compare_result<0
            high = mid - 1;
        }
    }

    return low;
}

void binary_insertion_sort(void* array_pointer, long array_size, size_t byte_size, int (*compare)(void*,void*)){
    if(array_pointer==NULL){
        fprintf(stderr,"array paramenter cannot be NULL\n");
        return;
    }
    if(compare==NULL){
        fprintf(stderr,"compare parameter cannot be NULL\n");
        return;
    }

    long i, j, position;
    void* key;

    for(i=0; i<array_size;++i){ 
        key = (array_pointer) + (i * byte_size); 
        j = i-1;
        position = binary_search(array_pointer, key, 0, j, byte_size, compare);
        //found position where element should move, now i swap the elements forward position * times until my key element is in position

        while(j>=position){

            swap(array_pointer + (j+1)*byte_size, array_pointer + (j*byte_size), byte_size);
            j--;
        }
    }
}


/* function that performs the partition operation of the Quick Sort algorithm by rearranging the element of the array so that
 * all the elements that are less than the pivot are placed before it and all the elements that are greater than the pivot
 * are placed after it. The function then returns the pivots final index. 
 * This specific version of the partition operation chooses the pivot as the left-most element of the array. 
*/
static long partition_left_pivot(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*)){
    
    //random_pivot_selection(array_pointer, left, right, byte_size); 
    void* pivot = array_pointer+(left*byte_size);

    long left_pointer = left+1; 
    long right_pointer = right;       
    while(left_pointer <= right_pointer){       
        if(compare(array_pointer+(left_pointer*byte_size), pivot)<0){      
            left_pointer++;        
        }
        else{
            if( compare(array_pointer+(right_pointer*byte_size), pivot)>0){  
                right_pointer--;
            }

            else{
               swap(array_pointer+left_pointer*(byte_size),array_pointer+right_pointer*(byte_size), byte_size);
               left_pointer++; 
               right_pointer--;       
            }
        }
    }
    //right_pointer = left_pointer -1 ; 

    swap(array_pointer+right_pointer*(byte_size),array_pointer+left*(byte_size), byte_size);//swap pivot con il right pointer

    return right_pointer;
} 


/* function that performs the partition operation of the Quick Sort algorithm by rearranging the element of the array so that
 * all the elements that are less than the pivot are placed before it and all the elements that are greater than the pivot
 * are placed after it. The function then returns the pivots final index. 
 * This specific version of the partition operation chooses the pivot at random and swaps it with the left-most element of the array. 
*/
static long partition_random_pivot(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*)){
    srand(time(0));
    long random_index = rand() % (right+1-left) + left;
    //long random_index = (right-left)/2;
    swap(array_pointer+left*byte_size, array_pointer+random_index*byte_size, byte_size);
    return partition_left_pivot(array_pointer, left, right, byte_size, compare);
}

/* function that performs the partition operation of the Quick Sort algorithm by rearranging the element of the array so that
 * all the elements that are less than the pivot are placed before it and all the elements that are greater than the pivot
 * are placed after it. The function then returns the pivots final index. 
 * This specific version of the partition operation chooses the pivot as the right-most element of the array. 
*/
static long partition_right_pivot(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*)){
    
    void* pivot = array_pointer+(right*byte_size);

    long left_pointer = left; 
    long right_pointer = right-1;       
    while(left_pointer <= right_pointer){       
        if(compare(array_pointer+(left_pointer*byte_size), pivot)<0){      
            left_pointer++;        
        }
        else{
            if( compare(array_pointer+(right_pointer*byte_size), pivot)>0 ){  
                right_pointer--;
            }

            else{
               swap(array_pointer+left_pointer*(byte_size),array_pointer+right_pointer*(byte_size), byte_size);
               left_pointer++; 
               right_pointer--;       
            }
        }
    }
    //left_pointer = right_pointer -1 ; 

    swap(array_pointer+left_pointer*(byte_size),array_pointer+right*(byte_size), byte_size);//swap pivot con il left pointer

    return left_pointer;
} 

void quick_sort(void* array_pointer, long left, long right, size_t byte_size, int (*compare)(void*, void*)){
    
    if(array_pointer==NULL || compare==NULL) return;
   
    long int p; 

    if(left<right){
        p = partition_random_pivot(array_pointer, left, right, byte_size, compare);
        quick_sort(array_pointer, left, p-1, byte_size, compare);
        quick_sort(array_pointer, p+1, right, byte_size ,compare);
    }

}


