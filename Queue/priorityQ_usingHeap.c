#include <stdio.h>

#define MAX 100

int heap[MAX];   // আমাদের heap array
int size = 0;    // heap এর বর্তমান size

// Function: Swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function: Heapify Up (Insert এর সময়)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    // যতক্ষণ parent আছে এবং parent ছোট child এর থেকে → swap করো
    if (index > 0 && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

// Function: Heapify Down (Delete এর সময়)
void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    // বাম child যদি বড় হয়
    if (left < size && heap[left] > heap[largest])
        largest = left;

    // ডান child যদি বড় হয়
    if (right < size && heap[right] > heap[largest])
        largest = right;

    // যদি largest index পরিবর্তন হয়ে থাকে → swap করো এবং recurse করো
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// Function: Insert element in Priority Queue
void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue পূর্ণ!\n");
        return;
    }
    heap[size] = value; // নতুন element শেষ position এ বসাও
    heapifyUp(size);    // উপরে তুলে heap ঠিক করো
    size++;
}

// Function: Remove highest priority element (Max)
int removeMax() {
    if (size <= 0) {
        printf("Priority Queue খালি!\n");
        return -1;
    }
    int max = heap[0];           // Root element (Highest Priority)
    heap[0] = heap[size - 1];    // শেষ element কে root এ বসাও
    size--;
    heapifyDown(0);              // নিচে নামিয়ে heap ঠিক করো
    return max;
}

// Function: Print heap (Priority Queue)
void printHeap() {
    printf("Priority Queue: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(5);
    insert(3);
    insert(8);
    insert(4);
    printHeap(); // দেখাবে: 8 4 5 3

    printf("Removed Max: %d\n", removeMax()); // 8 মুছে যাবে
    printHeap(); // দেখাবে: 5 4 3

    return 0;
}
