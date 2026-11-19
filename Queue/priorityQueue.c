#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;       // Item value
    int priority;   // Priority value
    struct Node* next;
};

// নতুন নোড তৈরি
struct Node* createnode(int d, int p) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

// Priority Queue-তে insert
void enqueue(struct Node** head, int d, int p) {
    struct Node* temp = *head;
    struct Node* newnode = createnode(d, p);

    // যদি queue খালি বা নতুন নোডের priority বেশি হয়
    if (*head == NULL || (*head)->priority < p) {
        newnode->next = *head;
        *head = newnode;
    }
    else {
        // সঠিক জায়গায় বসানো
        while (temp->next != NULL && temp->next->priority >= p) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Priority Queue থেকে delete (সবচেয়ে বেশি priority)
void dequeue(struct Node** head) {
    if (*head == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// সামনে থাকা element দেখা
int peek(struct Node* head) {
    if (head != NULL)
        return head->data;
    return -1;
}

// Queue খালি কিনা দেখা
int isEmpty(struct Node* head) {
    return head == NULL;
}

int main() {
    struct Node* pq = NULL;

    enqueue(&pq, 10, 2); // data=10, priority=2
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);

    printf("Top element: %d\n", peek(pq)); // 30 (priority=3)

    dequeue(&pq);
    printf("Top element after dequeue: %d\n", peek(pq)); // 10

    return 0;
}
