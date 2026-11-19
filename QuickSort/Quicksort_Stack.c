#include <stdio.h>

#define SIZE 100

// Swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (same as recursive version)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Iterative quicksort using stack
void quickSortIterative(int arr[], int low, int high) {
    // Stack for storing subarray indices
    int stack[SIZE];

    // Initialize top of stack
    int top = -1;

    // Push initial low and high
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping while stack is not empty
    while (top >= 0) {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Partition the array and get pivot index
        int p = partition(arr, low, high);

        // If left part exists, push its indices
        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // If right part exists, push its indices
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
