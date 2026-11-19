#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

int stack[SIZE];
int t = -1;

void push(int a) {
    if (t == SIZE - 1) {
        printf("******* Stack Overflow ********\n");
    } else {
        stack[++t] = a;
    }
}

int pop(void) {
    if (t < 0) {
        printf("******** Stack Underflow *******\n");
        return 0;
    } else {
        return stack[t--];
    }
}
// This function evaluates postfix expression from a string
void evaluate_postfix(char *expr) {
    char ch;
    int i = 0, a, b;

    while ((ch = expr[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');  // convert char digit to int
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            b = pop();
            a = pop();

            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': 
                    if (b != 0)
                        push(a / b);
                    else
                        printf("Division by zero error\n");
                    break;
            }
        }
    }

    printf("Final result on top of stack: %d\n", stack[t]);
}

int main() {
    char expr[100];
                printf("Enter postfix expression (e.g., 53+82-*): ");
                fflush(stdin);
                scanf("%s", expr);
                evaluate_postfix(expr);
    
    return 0;
}
