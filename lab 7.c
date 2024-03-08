#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n, int *total_swaps) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swapping elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*total_swaps)++;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n, int *total_swaps) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            // Swapping elements
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            (*total_swaps)++;
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int total_swaps1 = 0, total_swaps2 = 0;

    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        int swaps = 0;
        int temp_array1[n1];
        for (int j = 0; j < n1; j++) {
            temp_array1[j] = array1[j];
        }
        bubbleSort(temp_array1, n1, &swaps);
        printf("%d: %d\n", array1[i], swaps);
        total_swaps1 += swaps;
    }
    printf("total swaps: %d\n\n", total_swaps1);

    printf("array2:\n");
    for (int i = 0; i < n2; i++) {
        int swaps = 0;
        int temp_array2[n2];
        for (int j = 0; j < n2; j++) {
            temp_array2[j] = array2[j];
        }
        selectionSort(temp_array2, n2, &swaps);
        printf("%d: %d\n", array2[i], swaps);
        total_swaps2 += swaps;
    }
    printf("total swaps: %d\n", total_swaps2);

    return 0;
}
