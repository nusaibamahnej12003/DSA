#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

struct node* createnode(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void  insertfirst(struct node** head,int value)
{
    struct node* newnode=createnode(value);
    newnode->next = *head;
    *head=newnode;

}
void insertatlast(struct node** head,int value)
{
    struct node* newnode=createnode(value);
    if(*head==NULL)
    {
       *head = newnode;
       return;
    }
    struct node* temp = *head;
    while(temp->next!= NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertaftervalue(struct node*head, int target , int value)
{
    struct node* newnode = createnode(value);
    struct node*temp = *head;
    if(temp!=NULLL & temp->data!=target)
    {
        temp= temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deletelast(struct node* head)
{
    struct node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;


}
void deletebyValue(int node** head,int value)
{
    struct node* temp=*head;
    struct node* prevnode;
    while(temp!=NULL && temp->data!=value)
    {
        prevnode=temp
        temp=temp->next;
    }
    if(temp==NULL)
    {
      prevnode->next=NULL;
    }
    prevnode->next=temp->next;

}