#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Insert at end
void insertAtEnd(struct node** head, int value) {
    struct node* newnode = createNode(value);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

// Display function
void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//  Reverse Linked List (Iterative)
void reverseList(struct node** head) {
    struct node* prev = NULL;
    struct node* curr = *head;
    struct node* next = NULL;

    while (curr != NULL) {
        next = curr->next;     // Save next
        curr->next = prev;     // Reverse current node
        prev = curr;           // Move prev forward
        curr = next;           // Move curr forward
    }

    *head = prev; // Update the head pointer
}

int main() {
    struct node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Original List:\n");
    display(head);

    reverseList(&head);

    printf("Reversed List:\n");
    display(head);

    return 0;
}
