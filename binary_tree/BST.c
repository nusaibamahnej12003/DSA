#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(struct node *root,int value)
{
        if(root==NULL)
        {
            struct node *newnode;
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->left=NULL;
            newnode->right=NULL;
            return newnode;
        }
    
    if(value < root->data)
    {
       root->left=create(root->left,value);
    }
    else
    {
       root->right=create(root->right,value);
    }
    return root;

} 
// Find inorder successor (smallest in right subtree)
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
struct node* deleteNode(struct node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}


struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    struct node *root;
    root=0;
    int array[7]={8,4,3,6,11,13,5};
    for(int i=0;i<7;i++)
    {
       root=create(root,array[i]);
    }
    root=create(root,12);//Creation = Insertion
    printf("InOrder : \n");
    inorder(root);
    root=deleteNode(root,12);
    printf("\nInOrder : \n");
    inorder(root);

    int key = 6;
    struct node* found = search(root, key);

    if (found != NULL)
        printf("\nFound: %d\n", found->data);
    else
        printf("\nNot found\n");
}