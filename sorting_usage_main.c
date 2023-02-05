#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



#include "arrays_sorting_lib.h"

#define INITIAL_CAPACITY 2 

typedef struct Record{
    int id; 
    char* string_field;
    int int_field;
    double double_field;
} Record;
/*loads from a input file the Records array*/
static int load_array(const char* file_name, Record** array_of_records_pointer_adr, long capacity){
    
    long index_of_record = 0; //will be the size of the array;
    char* read_line_p;
    char buffer[1024];
    int buf_size = 1024;
    FILE* fp;

    *array_of_records_pointer_adr = malloc(sizeof(Record) * capacity);
    if(*array_of_records_pointer_adr == NULL){
        fprintf(stderr,"load_array: Memory allocation error at array_of_records");
        exit(EXIT_FAILURE);
    }

    printf("Loading records in array_of_records from .csv file\n");
    fp = fopen(file_name, "r");
    if(fp==NULL){
        fprintf(stderr, "main: unable to open the file");
        exit(EXIT_FAILURE);
    }
   
    while(fgets(buffer,buf_size,fp)!=NULL){
        read_line_p = malloc((strlen(buffer)+1)*sizeof(char));
        if(read_line_p == NULL){
            fprintf(stderr,"main: unable to allocate memory for the read line");
            exit(EXIT_FAILURE);
        }   
        strcpy(read_line_p,buffer);
        char* field[4]; 
        field[0] = strtok(read_line_p, ",");

        int i = 1;
        while(i<4){
            field[i] = strtok(NULL, ",");
            i++;
        }
        
        int id_value = atoi(field[0]);

        char* string_value = malloc((strlen(field[1])+1) * sizeof(char));
        if(string_value == NULL){
            fprintf(stderr,"load_array: unable to allocate memory for string_value");
            exit(EXIT_FAILURE);
        }
        
        strcpy(string_value, field[1]);
        int int_value = atoi(field[2]);
        double double_value = atof(field[3]);

        if(index_of_record>=capacity){  
            *array_of_records_pointer_adr = (Record*)realloc(*array_of_records_pointer_adr,2*capacity*sizeof(Record));
            capacity = 2*capacity;    
        }


        (*array_of_records_pointer_adr+index_of_record)->id = id_value;
        (*array_of_records_pointer_adr+index_of_record)->int_field = int_value;
        (*array_of_records_pointer_adr+index_of_record)->double_field = double_value;

        ((*array_of_records_pointer_adr)+index_of_record)->string_field = (char*) malloc(20 * sizeof(char));
        strcpy(((*array_of_records_pointer_adr)+index_of_record)->string_field, string_value);

        index_of_record++;

        free(string_value);
        free(read_line_p);
    }
    fclose(fp);
    printf("\nRecords loaded successfully from .csv file");
    return index_of_record;
}
/* It takes as input two pointers to struct record.
 * It returns -1 if the integer field of the first record is less than 
 * the integer field of the second one, 0 if they are equal, 1 otherwise
 * */
static int compare_int_field_record(void* record1, void* record2){
    if(record1 == NULL){
        fprintf(stderr, "precedes_record_int_field: first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(record2 == NULL){
        fprintf(stderr, "precedes_record_int_field: second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    Record* rec1 = (Record*) record1; 
    Record* rec2 = (Record*) record2;

    if(rec1->int_field == rec2->int_field){
        return 0;
    }
    else if(rec1->int_field > rec2->int_field){
        return 1;
    }
    else{
        return -1;
    }
}

static int compare_double(double f1, double f2){
    double precision = 0.00001;
    if ((f1-precision)>f2){
        return 1;
    }
    else if((f1+precision)<f2){
        return -1;
    }
    else{
        return 0;
    }
}

/* It takes as input two pointers to struct record.
 * It returns the result of the strcmp() function using the string field of the first record as first parameter
 * and the string field of the second record as second parameter. 
 * */
static int compare_string_field_record(void* record1, void* record2){
    if(record1 == NULL){
        fprintf(stderr, "precedes_record_string_field: first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(record2 == NULL){
        fprintf(stderr, "precedes_record_string_field: second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    Record* rec1 = (Record*) record1; 
    Record* rec2 = (Record*) record2;
    
    int compare_result = strcmp(rec1->string_field,rec2->string_field);
    
    if(compare_result<0){
        return -1;
    }
    
    else if(compare_result>0){
        return 1;
    }
    
    else{
        return 0;
    } 
}

/* It takes as input two pointers to struct record.
 * It returns -1 if the double field of the first record is less than 
 * the double field of the second one, 0 if they are equal, 1 otherwise
 * */
static int compare_double_field_record(void* record1, void* record2){
    if(record1 == NULL){
        fprintf(stderr, "precedes_record_double_field: first parameter is a null pointer");
        exit(EXIT_FAILURE);
    }
    if(record2 == NULL){
        fprintf(stderr, "precedes_record_double_field: second parameter is a null pointer");
        exit(EXIT_FAILURE);
    }

    Record* rec1 = (Record*) record1; 
    Record* rec2 = (Record*) record2;

    int compare_result = compare_double(rec1->double_field, rec2->double_field);

    if(compare_result<0){
        return -1;
    }
    
    else if(compare_result>0){
        return 1;
    }
    
    else{
        return 0;
    } 
}

static int compare_int(void* int1, void* int2){
    int* i = (int*) int1;
    int* j = (int*) int2;


    if(*i==*j){return 0;}
    else if(*i>*j){return 1;}
    else return -1;

}

static void print_records_array(Record* array, long size){
    for(int i=0;i<size;i++){
        printf("id value:     %d,       ",  ((array+i)->id));
        printf("string_value: %s,   "    ,  ((array+i)->string_field));
        printf("int_value:    %d,      " ,  ((array+i)->int_field));
        printf("double_value: %f\n  "    ,  ((array+i)->double_field));
    }
    
}

static void free_records_array(Record* array, long size){
    for(int i=0;i<size;i++){
        free ( (array+i)->string_field);
    }
    free(array);
    printf("\n\n#########################just freed the Records########################################\n\n");

}

int main(int argc, char const *argv[]){
    if(argc < 2){
        printf("Missing Records.csv file when running the program\n");
        exit(EXIT_FAILURE);
    }

    clock_t start, end;
    double time_needed;


    long array_size;
    long capacity = INITIAL_CAPACITY;
    Record* array_of_records = NULL;
    array_size = load_array(argv[1], &array_of_records, capacity);

    /*##########################  BINARY_INSERTION_SORT PART   #############################################################
    printf("\nSORTING RECORD BY INTEGER_FIELD WITH BINARY_INSERTION_SORT:\n");
    binary_insertion_sort((void*)array_of_records, array_size, sizeof(Record), compare_int_field_record); 
    print_records_array(array_of_records, array_size);

    printf("\nSORTING RECORD BY STRING_FIELD WITH BINARY_INSERTION_SORT:\n");
    binary_insertion_sort((void*)array_of_records, array_size, sizeof(Record), compare_string_field_record); 
    print_records_array(array_of_records, array_size);

    printf("\nSORTING RECORD BY DOUBLE_FIELD WITH BINARY_INSERTION_SORT:\n");
    binary_insertion_sort((void*)array_of_records, array_size, sizeof(Record), compare_double_field_record); 
    print_records_array(array_of_records, array_size);
    */
    
        
    /*################################ QUICK_SORT PART #####################################################################*/
    
    
    printf("\nSORTING RECORD BY INTEGER_FIELD WITH QUICK_SORT:\n");
    start = clock();
    quick_sort((void*)array_of_records, 0, array_size-1, sizeof(Record), compare_int_field_record); 
    time_needed = clock() - start;
    time_needed = ((double) time_needed) / CLOCKS_PER_SEC;
    //print_records_array(array_of_records, array_size);
    printf("\ntime needed for quick_sort: %f\n", time_needed);

    //printf("\nSORTING RECORD BY STRING_FIELD WITH QUICK_SORT:\n");
    //quick_sort((void*)array_of_records, 0, array_size-1, sizeof(Record), compare_string_field_record); 
    //print_records_array(array_of_records, array_size);

    //printf("\nSORTING RECORD BY DOUBLE_FIELD WITH QUICK_SORT:\n");
    //quick_sort((void*)array_of_records, 0, array_size-1, sizeof(Record), compare_double_field_record); 
    //print_records_array(array_of_records, array_size);
    /**##############################################################################################################*/
   






    
    free_records_array(array_of_records, array_size);

    return 0;
}