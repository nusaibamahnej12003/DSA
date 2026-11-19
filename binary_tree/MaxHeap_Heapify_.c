#include <stdio.h>
//Normal Max Heap
// দুইটা উপাদান অদল-বদল করার ফাংশন
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify: কোনো একটা index থেকে শুরু করে subtree-টাকে max-heap বানায়
void heapify(int arr[], int n, int i) {
    int largest = i;        // ধরছি i-ই সবচেয়ে বড়
    int left = 2 * i + 1;   // left child index
    int right = 2 * i + 2;  // right child index

    // যদি বাম সন্তান বড় হয়
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // যদি ডান সন্তান বড় হয়
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // যদি কোনো child বড় হয়, তাহলে swap করে আবার নিচে heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// পুরো array-কে Max-Heap এ রূপান্তর করার ফাংশন
void buildMaxHeap(int arr[], int n) {
    // শেষ non-leaf node থেকে শুরু করে উপরের দিকে heapify করি
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Array প্রিন্ট করার ফাংশন
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    buildMaxHeap(arr, n);

    printf("Array after building Max-Heap:\n");
    printArray(arr, n);

    return 0;
}
