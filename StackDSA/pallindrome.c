#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
   }
   return '\0';
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }


    for (int i = 0; i < len; i++) {
        char c = pop();
        if (c != str[i]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
