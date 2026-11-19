#include <stdio.h>
#define MAX 100
int stack1[MAX],top1 = -1;
int stack2[MAX],top2 = -1;

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter stack elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        stack1[++top1] = val;
    }
    while (top1 != -1) {
        int temp = stack1[top1--]   ;

        while (top2 != -1 && stack2[top2] > temp) {
            stack1[++top1] = stack2[top2--];
        }

        stack2[++top2] = temp;
    }


    printf("\nSorted stack :\n");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    return 0;
}