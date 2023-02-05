#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unity.h"
#include "arrays_sorting_lib.h"

/*Test suite for the array sorting library sorting algorithms */


/*Compare function that will be used in tests*/
static int compare_int(void* int1, void* int2){
    int* i = (int*) int1;
    int* j = (int*) int2;


    if(*i==*j){return 0;}
    else if(*i>*j){return 1;}
    else return -1;

}

//data elements that are initialized before each test
static int* tested_array; 


/*initialize function that will be running before each test*/
void setUp(void){
    tested_array = NULL;
}
/*end function that will be running after each test*/
void tearDown(void){
    free(tested_array);
}

/////////////////////////////////UNIT TEST START//////////////////////////////////////////////////////////////////////////////////////


static void test_binary_insertion_sort_NULL(void){

    binary_insertion_sort(tested_array, 0, sizeof(int), compare_int);
    TEST_ASSERT(tested_array==NULL);
}

static void test_binary_insertion_sort_one_el(void){

    int exp_arr[] = {22};

    tested_array = malloc(sizeof(int)*1);
    tested_array[0] = 22;
    
    binary_insertion_sort((void*)tested_array, 1, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 1);
}

static void test_binary_insertion_sort_two_el(void){

    int exp_arr[] = {22, 43};

    tested_array = malloc(sizeof(int)*2);
    tested_array[0] = 43;
    tested_array[1] = 22;

    binary_insertion_sort((void*)tested_array, 2, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 2);
}

static void test_binary_insertion_sort_avg_case(void){
    int exp_arr[] = {4, 20, 31, 45, 50};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 45;
    tested_array[1] = 20;
    tested_array[2] = 4;
    tested_array[3] = 31;
    tested_array[4] = 50;
  
    binary_insertion_sort((void*)tested_array, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);
}

static void test_binary_insertion_sort_reverse(void){
    int exp_arr[] = {4, 20, 31, 45, 50};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 50;
    tested_array[1] = 45;
    tested_array[2] = 31;
    tested_array[3] = 20;
    tested_array[4] = 4;
  
    binary_insertion_sort((void*)tested_array, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);
}

static void test_binary_insertion_sort_already_ordered(void){
    int exp_arr[] = {4, 20, 31, 45, 50};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 4;
    tested_array[1] = 20;
    tested_array[2] = 31;
    tested_array[3] = 45;
    tested_array[4] = 50;
  
    binary_insertion_sort((void*)tested_array, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);
}

static void test_binary_insertion_sort_all_equals(void){
    int exp_arr[] = {15, 15, 15, 15, 15};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 15;
    tested_array[1] = 15;
    tested_array[2] = 15;
    tested_array[3] = 15;
    tested_array[4] = 15;
  
    binary_insertion_sort((void*)tested_array, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);

}


static void test_quick_sort_NULL(void){

    quick_sort(tested_array, 0, 0, sizeof(int), compare_int);
    TEST_ASSERT(tested_array==NULL);
}

static void test_quick_sort_one_el(void){

    int exp_arr[] = {22};

    tested_array = malloc(sizeof(int)*1);
    tested_array[0] = 22;
    
    quick_sort((void*)tested_array, 0, 1, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 1);
}

static void test_quick_sort_two_el(void){

    int exp_arr[] = {22, 43};

    tested_array = malloc(sizeof(int)*2);
    tested_array[0] = 43;
    tested_array[1] = 22;

    quick_sort((void*)tested_array, 0, 2, sizeof(int), compare_int);
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 2);
}

static void test_quick_sort_avg_case(void){
    int exp_arr[] = {4, 20, 31, 45, 50};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 45;
    tested_array[1] = 20;
    tested_array[2] = 4;
    tested_array[3] = 31;
    tested_array[4] = 50;
  
    quick_sort((void*)tested_array, 0, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);
}

static void test_quick_sort_reverse(void){
    int exp_arr[] = {4, 20, 31, 45, 50};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 50;
    tested_array[1] = 45;
    tested_array[2] = 31;
    tested_array[3] = 20;
    tested_array[4] = 4;
  
    quick_sort((void*)tested_array, 0, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);
}

static void test_quick_sort_already_ordered(void){
    int exp_arr[] = {4, 20, 31, 45, 50};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 4;
    tested_array[1] = 20;
    tested_array[2] = 31;
    tested_array[3] = 45;
    tested_array[4] = 50;
  
    quick_sort((void*)tested_array, 0, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);
}

static void test_quick_sort_all_equals(void){
    int exp_arr[] = {15, 15, 15, 15, 15};
    
    tested_array = malloc(sizeof(int) * 5);
    tested_array[0] = 15;
    tested_array[1] = 15;
    tested_array[2] = 15;
    tested_array[3] = 15;
    tested_array[4] = 15;
  
    quick_sort((void*)tested_array, 0, 5, sizeof(int), compare_int);
    
    TEST_ASSERT_EQUAL_INT16_ARRAY(exp_arr, tested_array, 5);

}

//////////////////////////////////////////////UNIT TEST END////////////////////////////////////////////////////////////////////////


int main(){

    //test session
    UNITY_BEGIN();

    RUN_TEST(test_binary_insertion_sort_NULL);
    RUN_TEST(test_binary_insertion_sort_one_el);
    RUN_TEST(test_binary_insertion_sort_two_el);
    RUN_TEST(test_binary_insertion_sort_avg_case);
    RUN_TEST(test_binary_insertion_sort_reverse);
    RUN_TEST(test_binary_insertion_sort_already_ordered);
    RUN_TEST(test_binary_insertion_sort_all_equals);

    RUN_TEST(test_quick_sort_NULL);
    RUN_TEST(test_quick_sort_one_el);
    RUN_TEST(test_quick_sort_two_el);
    RUN_TEST(test_quick_sort_avg_case);
    RUN_TEST(test_quick_sort_reverse);
    RUN_TEST(test_quick_sort_already_ordered);
    RUN_TEST(test_quick_sort_all_equals);

    
    return UNITY_END();
}