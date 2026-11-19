#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    int id;
    struct node* next;
};

struct node* createNode(char *name,int id) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->name,name);
    newnode->id=id;
    newnode->next = NULL;
    return newnode;
}

void insertAtLast(struct node** head, char *name,int value) {
    struct node* newnode = createNode(name,value);

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

void insertAtFirst(struct node** head,char *name, int value) {
    struct node* newnode = createNode(name,value);
    newnode->next = *head;
    *head = newnode;
}

void insertAfterValue(struct node* head, int target,char* name, int value) {
    struct node* temp = head;
    while (temp != NULL && temp->id != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", target);
        return;
    }

    struct node* newnode = createNode(name,value);
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
void deleteByValue(struct node** head,int value)
{
    struct node* temp = *head;
    struct node* prenode;
    if (temp->id == value) {
        deletefirst(head);//head is already address of the head pointer.
    }
    else
    {

    while(temp->id!=value)
    {
        prenode=temp;
        temp=temp->next;
    }
    
    prenode->next=temp->next;
    }
}
void displayList(struct node* head) {
    struct node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Student List:\n ");
    while (temp != NULL) {
        printf("Name: %s , ID =%d \n", temp->name,temp->id);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, value, target,id;
    char name[100];
   
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Last\n");
        printf("2. Insert at First\n");
        printf("3. Insert After a ID\n");
        printf("4. Display List\n");
        printf("5.Delete At First\n");
        printf("6.Delete The Last Student\n");
        printf("7.Delete by ID\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name to insert at first: ");
                getchar();
                fgets(name,sizeof(name),stdin);
                name[strcspn(name, "\n")] = '\0'; 
                fflush(stdin);
                printf("Enter student's ID : ");
                scanf("%d", &value);
                insertAtLast(&head,name, value);
                break;

            case 2:
                printf("Enter name to insert at first: ");
                getchar();
                fgets(name,sizeof(name),stdin);
                name[strcspn(name, "\n")] = '\0'; 
                fflush(stdin);
                printf("Enter student's ID : ");
                scanf("%d", &value);
                insertAtFirst(&head,name, value);
                break;

            case 3:
                printf("Enter ID after which to insert: ");
                scanf("%d", &target);
                printf("Enter name to insert at first: ");
                getchar();
                fgets(name,sizeof(name),stdin);
                name[strcspn(name, "\n")] = '\0'; 
                fflush(stdin);
                printf("Enter student's ID : ");
                scanf("%d", &value);
                insertAfterValue(head, target, name,value);
                break;

            case 4:
                displayList(head);
                break;
            case 5:
                deletefirst(&head);
                break;
            case 6:
                deletelast1(head);
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
