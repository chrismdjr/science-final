#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
}


void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
}


int main() {
    printf("Opening data.csv...\n");
    
    struct stat statbuf;
    char* buffer;
    int* data;

    FILE* file_ptr = fopen("../data.csv", "r");

    if (file_ptr == NULL) {
        printf("You must run generate_dataset.py to generate a dataset.\n");
        return 0;
    }

    int status = stat("../data.csv", &statbuf);

    if (status != 0) {
        perror("Stat failed.\n");
        return 1;
    }

    buffer = (char*) malloc(statbuf.st_size);
    buffer[statbuf.st_size - 1] = '\0';

    fread(buffer, statbuf.st_size, 1, file_ptr);

    char *token_pointer;
    int i = 0;

    data = (int*) malloc(104857600);
    token_pointer = strtok(buffer, ",");

    while (token_pointer) {
        int int_char = atoi(token_pointer);

        data[i++] = int_char;
        token_pointer = strtok(NULL, ",");
    }
    
    int data_size = i;
    printf("[RUNNING IN C] Sorting unsorted dataset of %d integers...\n", i);
    clock_t benchmark_start = clock();
    
    quick_sort(data, 0, data_size - 1);

    printf("Sorted array in %0.4fs.\n", (float)((clock() - benchmark_start))/CLOCKS_PER_SEC);
    return 0;
}