#include<stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack1[SIZE], top1 = -1;
int stack2[SIZE], top2 = -1;

void push1(int val) { stack1[++top1] = val; }
void push2(int val) { stack2[++top2] = val; }

int pop1() { return stack1[top1--]; }
int pop2() { return stack2[top2--]; }

int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }

void enqueue(int val) {
    push1(val);  
    printf("Enqueued: %d\n", val);
}

void dequeue() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is empty\n");
        return;
    }

    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1()); // stack1 থেকে সব কিছু উল্টে stack2 তে
        }
    }

    int val = pop2();
    printf("Dequeued: %d\n", val);
}
void display()
{
    if(!isEmpty2())
    {
    printf("The Queue is : \n");
    for(int i=top2;i>=0;i--)
    {
        printf("%d\n",stack2[i]);
    }
    for(int i=0;i<=top1;i++)
    {
        printf("%d\n",stack1[i]);
    }
  }
  else {
            printf("The Queue is : \n");
            for (int i = 0; i <= top1; i++) {
            printf("%d\n", stack1[i]);
        }
    }
}


int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue(); // 10
    dequeue(); // 20

    enqueue(40);
    dequeue(); // 30
    display();

    return 0;
}
