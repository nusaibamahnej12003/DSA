#include <stdio.h>
#define MAX_SIZE 15

int bst[MAX_SIZE];

void initializeBST() {
    for (int i = 0; i < MAX_SIZE; i++) {
        bst[i] = -1;
    }
}

int insert(int value, int i) {
    if (i >= MAX_SIZE) {
        printf("Out of bounds!\n");
        return 0;
    }

    if (bst[i] == -1) {
        bst[i] = value;
        return 1;
    }

    if (value < bst[i]) {
        return insert(value, 2 * i + 1);
    } else if (value > bst[i]) {
        return insert(value, 2 * i + 2);
    } else {
        return 0;
    }
}

// Sequentially print the whole array (including empty spots)
void printArray() {
    printf("BST array representation:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (bst[i] != -1)
            printf("%d ", bst[i]);
        else
            printf("_ ");  // empty spot
    }
    printf("\n");
}

int main() {
    initializeBST();

    insert(15, 0);
    insert(10, 0);
    insert(5, 0);
    insert(8, 0);
    insert(12, 0);
    insert(25, 0);

    printArray();

    return 0;
}
