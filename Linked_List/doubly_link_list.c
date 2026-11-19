#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insertAtLast(struct node** head, int value) {
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
    newnode->prev=temp;
}
void insertAtFirst(struct node** head, int value) {
    struct node* newnode = createNode(value);
    newnode->next = *head;
    *head = newnode;
    struct node* second;
    second=newnode->next;
    second->prev=newnode;
    
}
void deleteByValue(struct node** head,int value) {
    struct node* temp = *head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", value);
}
void insertBeforeValue(struct node** head,int target,int value)
{
    struct node* newnode=createNode(value);
    struct node* temp= *head;
    while(temp!=NULL && temp->data!= target)
    {
        temp=temp->next;
    }
    if(temp->prev!=NULL){
    newnode->prev=temp->prev;
    newnode->next=temp;
    temp->prev->next=newnode;
    temp->prev=newnode;}

    else
    {
         *head =newnode;
         newnode->prev=NULL;
        newnode->next=temp;
    }

}


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
int main() {
    struct node* head = NULL;
    int choice, value,target;
   
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Last\n");
        printf("2. Insert at First\n");
        printf("3. Insert Before a Value\n");
        printf("4. Display List\n");
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
                insertAtFirst(&head,value);
                break;

            case 3:
                printf("Enter value before which to insert: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertBeforeValue(&head,target,value);
                break;

            case 4:
                displayList(head);
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
