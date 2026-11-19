#include <stdio.h>

#define SIZE 32

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top < SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return -1; 
    }
}


void decimalToBinary(int num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (num > 0) {
        
        push(num % 2);
        num = num / 2;
    }

    printf("Binary: ");
    while (top>=0) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int number;

    printf("Enter a decimal number: ");
    scanf("%d", &number);

    decimalToBinary(number);

    return 0;
}
