#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack[size],stackindex=-1;
int preorder[size],preindex=-1;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
int push(int value)
{  
        stackindex++;
        stack[stackindex]=value;  
}
int pop(void)
{
        int p= stack[stackindex];
        stackindex--;  
        return p;     
}
struct node *create()
{
    int x;
    struct node *newnode;
    newnode= (struct node*)malloc(sizeof(struct node));
    printf("Enter data for the node(-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
    {return 0;}
    newnode->data=x;
    printf("Enter left child of %d\n",x);
    newnode->left=create();
    printf("Enter right child of %d",x);
    newnode->right=create();
}
void order(struct node* root)
{
    if(root==NULL){return;}
    struct node* root2 = root->right;
  preorder[preindex++]= root->data;
  if(root->right!=NULL){
      push(root->right->data);

  }
  root=root->left;
  while(root->left!=NULL)
  {
    order(root);
  }
  while(stackindex!=-1)
  {
    preorder[++preindex]=pop();
  }
  int flag = -2;
  if(flag==-2){
if(root2->right!=NULL){
      push(root2->right->data);

  }  
  root2=root2->left;

  while(root2->left!=NULL)
  {
   order(root2); 
  }
  while(stackindex!=-1)
  {
    preorder[++preindex]=pop();
  }
  }



}
void display(void)
{
    printf("The stack is :\n");
    for(int i=0;i<=preindex;i++)
    {
        printf("%d\n",preorder[i]);
    }

}

int main()
{
    struct node *root=create();
   
    order(root);
    display();
}