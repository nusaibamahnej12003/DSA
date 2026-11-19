#include <stdio.h>
#include <stdlib.h>


struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};


struct tree* createNode(int value) {
    struct tree* newNode = (struct tree*) malloc(sizeof(struct tree));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct tree* insert(struct tree* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


void printTree(struct tree* root, int space) {
    if (root == NULL)
        return;

    
    space += 5;

    
    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    
    printTree(root->left, space);
}

int main() {
    struct tree* root = NULL;

 
    root= insert(root, 50);
    insert(root, 30);
    insert(root, 55);
    insert(root, 20);
    insert(root, 40);
    insert(root, 66);
    insert(root, 85);

    printf("Binary Search Tree:\n");
    printTree(root, 0);

    return 0;
}
