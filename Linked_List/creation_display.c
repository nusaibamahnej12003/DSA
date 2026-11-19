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

// Insert at the end
void insertAtLast(struct node **head, int value) {
    struct node* newnode = createNode(value);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Insert at the beginning
void insertAtFirst(struct node **head, int value) {
    struct node* newnode = createNode(value);
    newnode->next = *head;
    *head = newnode;
}

// Insert after a specific value
void insertAfterValue(struct node* head, int target, int value) {
    struct node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", target);
        return;
    }

    struct node* newnode = createNode(value);
    newnode->next = temp->next;
    temp->next = newnode;
}
void deletefirst(struct node** head)
{
    struct node* temp=*head;
    *head=temp->next;
}
void deletelast1(struct node* head)
{
    struct node* temp = head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deletelast2(struct node* head)
{
    struct node* temp=head;
    struct node* prenode;
    while(temp->next != NULL)
    {
        prenode=temp;
        temp=temp->next;
    }
    prenode->next=NULL;
}
void deleteByValue(struct node** head,int value)//nije akta pointer ,,*head =pointer ar value,**head = head,,head ar address
{
    struct node* temp = *head;
    struct node* prenode;
    if (temp->data == value) {
        deletefirst(head);//head is already address of the head pointer.
    }
    else
    {

    while(temp->data!=value)
    {
        prenode=temp;
        temp=temp->next;
    }
    
    prenode->next=temp->next;
    }
}
// Display the list
void displayList(struct node* head) {
    struct node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct node* head = NULL;
    int choice, value, target;
   
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Last\n");
        printf("2. Insert at First\n");
        printf("3. Insert After a Value\n");
        printf("4. Display List\n");
        printf("5.Delete At First\n");
        printf("6.Delete At Last 2 value\n");
        printf("7.Delete by value\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at last: ");
                scanf("%d", &value);
                insertAtLast(&head, value);
                break;

            case 2:
                printf("Enter value to insert at first: ");
                scanf("%d", &value);
                insertAtFirst(&head, value);
                break;

            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAfterValue(head, target, value);
                break;

            case 4:
                displayList(head);
                break;
            case 5:
                deletefirst(&head);
                break;
            case 6:
                deletelast1(head);
                deletelast2(head);
                break;
            case 7:
                printf("Enter value to delete : ");
                scanf("%d",&value);
                deleteByValue(&head,value);
                break;
            case 10:
                printf("Exiting...\n");
                return 0;
           

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
