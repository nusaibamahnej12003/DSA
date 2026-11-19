#include <stdio.h>
#define SIZE 20

int stack[SIZE], stack2[SIZE], sortstack[SIZE];
int t = -1;   // top of main stack
int k = -1;   // top of sortstack

void push(int a) {
    stack[++t] = a;
}

int pop() {
    return stack[t--];
}

void deletemin() {
    if (t == -1) return; // Base case: stack is empty

    int min = stack[0];

    // Find the minimum value
    for (int i = 1; i <= t; i++) {
        if (stack[i] < min) {
            min = stack[i];
        }
    }

    int j = -1; // temp stack2 top
    int found = 0;

    // Remove min from main stack, push others to temp
    while (t != -1) {
        int val = pop();
        if (val == min && !found) {
            found = 1; // remove only one occurrence
        } else {
            stack2[++j] = val;
        }
    }

    // Save min to sorted stack
    sortstack[++k] = min;

    // Restore other elements back to main stack
    while (j != -1) {
        push(stack2[j--]);
    }

    // Recurse
    deletemin();
}

void display() {
    printf("Sorted values (ascending): ");
    for (int i = 0; i <= k; i++) {
        printf("%d ", sortstack[i]);
    }
    printf("\n");
}

int main() {
    int n, num;

    printf("How many numbers do you want to push: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        push(num);
    }

    deletemin();
    display();

    return 0;
}
