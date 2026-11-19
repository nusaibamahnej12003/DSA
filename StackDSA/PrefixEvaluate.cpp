#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to apply an operator to two operands
int applyOperator(char op, int a, int b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // assumes b != 0
        default: return 0;
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(const string& expr) {
    stack<int> st;

    // Traverse from right to left
    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];

        if (isdigit(c)) {
            st.push(c - '0'); // Convert char to int
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (st.size() < 2) {
                cerr << "Error: Not enough operands.\n";
                return -1;
            }
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int result = applyOperator(c, op1, op2);
            st.push(result);
        }
        else if (c != ' ') {
            cerr << "Error: Invalid character '" << c << "'.\n";
            return -1;
        }
    }

    if (st.size() != 1) {
        cerr << "Error: Invalid prefix expression.\n";
        return -1;
    }

    return st.top();
}

int main() {
    string expr;
    cout << "Enter prefix expression (e.g. +9*26): ";
    cin >> expr;

    int result = evaluatePrefix(expr);
    if (result != -1) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
