#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preorderStack(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right) stack[++top] = current->right;
        if (current->left)  stack[++top] = current->left;
    }
}

int main() {
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Preorder: ");
    preorderStack(root);
    return 0;
}
