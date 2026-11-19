#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortIterative(int arr[], int n) {
    int leftStack[MAX], rightStack[MAX], stepStack[MAX];
    int top = -1;

    // Initial full array
    top++;
    leftStack[top] = 0;
    rightStack[top] = n - 1;
    stepStack[top] = 0; // 0 = divide, 1 = merge

    while (top >= 0) {
        int l = leftStack[top];
        int r = rightStack[top];
        int step = stepStack[top];
        top--;

        if (l >= r) continue;

        int m = (l + r) / 2;

        if (step == 0) {
            // First divide step, push merge and two halves
            top++;
            leftStack[top] = l;
            rightStack[top] = r;
            stepStack[top] = 1; // merge later

            top++;
            leftStack[top] = m + 1;
            rightStack[top] = r;
            stepStack[top] = 0; // divide right half

            top++;
            leftStack[top] = l;
            rightStack[top] = m;
            stepStack[top] = 0; // divide left half
        } else {
            // Now do merge
            merge(arr, l, m, r);
        }
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSortIterative(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
