#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Generates an array of random integers of given size.
int* generateArray(int size){
    int *arr = (int*)malloc(size * sizeof(int));
    
    for(int i=0;i<size;i++)
        arr[i] = rand();

    return arr;
}

// Sorts the given array using Bubble Sort.
void applyBubbleSort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

// Sorts the given array using Insertion Sort.
void applyInsertionSort(int arr[], int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

// Sorts the given array using Selection Sort.
void applySelectionSort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size){
    for (int i=0;i<size-1;i++){
        if (arr[i]<=arr[i+1]) 
            continue;
        else
            return false;
    }
    return true;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate random array
    int *arr = generateArray(size);

    // Start timer
    clock_t start = clock();

    // Apply sorting algorithm
    applyBubbleSort(arr, size);

    // Stop timer
    clock_t end = clock();

    // Calculate execution time
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Verify correctness
    if (verifySort(arr, size)) {
        printf("Array is sorted successfully.\n");
    } else {
        printf("Sorting failed!\n");
    }

    printf("Execution Time: %.6f seconds\n", executionTime);
    printf("Execution Time: %.3f milliseconds\n", executionTime * 1000);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}