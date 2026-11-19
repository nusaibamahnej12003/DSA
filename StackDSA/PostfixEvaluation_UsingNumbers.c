#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Stack operations
void push(Stack *s, int value) {
    if (s->top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char *expr) {
    Stack s;
    s.top = -1;

    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            // If token is a number (including negative)
            push(&s, atoi(token));
        } else {
            // Operator
            int b = pop(&s);
            int a = pop(&s);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) {
                        printf("Division by zero!\n");
                        exit(1);
                    }
                    result = a / b; 
                    break;
                default:
                    printf("Unknown operator: %s\n", token);
                    exit(1);
            }

            push(&s, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&s);
}

// Main function
int main() {
    char input[256];
    printf("Enter postfix expression (space-separated):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline

    int result = evaluatePostfix(input);
    printf("Result: %d\n", result);

    return 0;
}
