#include<iostream>
using namespace std;

void swap(int &a, int &b) { 
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start < end) {
        while(arr[start] <= pivot && start <= ub) {
            start++;
        }
        while(arr[end] > pivot && end >=lb) {
            end--;
        }
        if(start < end) {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}


void quicksort(int array[], int lb, int ub) {
    int stack[ub - lb + 1];
    int top = -1;
    stack[++top] = lb;
    stack[++top] = ub;

    while (top >= 0) {

        ub = stack[top--];
        lb = stack[top--];

        int loc = partition(array, lb, ub);

        if (loc - 1 > lb) {
            stack[++top] = lb;
            stack[++top] = loc - 1;
        }
        if (loc + 1 < ub) {
            stack[++top] = loc + 1;
            stack[++top] = ub;
        }
    }
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
