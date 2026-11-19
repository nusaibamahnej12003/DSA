#include <stdio.h>
#define SIZE 100

int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow on Stack 1!\n");
        return;
    }
    arr[++top1] = value;
}


void push2(int value) {
    if (top2 - 1 == top1) {
        printf("Stack Overflow on Stack 2!\n");
        return;
    }
    arr[--top2] = value;
}


int pop1() {
    if (top1 == -1) {
        printf("Stack Underflow on Stack 1!\n");
        return -1;
    }
    return arr[top1--];
}


int pop2() {
    if (top2 == SIZE) {
        printf("Stack Underflow on Stack 2!\n");
        return -1;
    }
    return arr[top2++];
}

void display1() {
    printf("Stack 1: ");
    for (int i = top1; i >=0; i--)
        printf("%d ", arr[i]);
    printf("\n");
}


void display2() {
    printf("Stack 2: ");
    for (int i = top2; i <=SIZE -1 ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    push1(10);
    push1(20);
    push1(30);
    
    push2(100);
    push2(90);
    push2(80);

    printf("After pushes:\n");
    display1();
    display2();

    printf("\nPopped from Stack 1: %d\n", pop1());
    printf("Popped from Stack 2: %d\n", pop2());

    printf("\nAfter pops:\n");
    display1();
    display2();

    return 0;
}
