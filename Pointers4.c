// Bubble sort using pointers
#include <stdio.h>
#include <stdlib.h>

void swap(int *element1Ptr, int *element2Ptr) {

    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

void bubbleSort(int array[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {

    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(sizeof(int) * size); // int *array = (int *)malloc(size * sizeof(int));
    
    if (array == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    printf("Please enter %d integers that you want to sort:\n", size);
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    bubbleSort(array, size);
    printf("Sorted array:\t");

    for (int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    return 0;
}
