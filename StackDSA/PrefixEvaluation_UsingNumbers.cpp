#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Check if the string is operator
bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

// Evaluate prefix expression
int evaluatePrefix(const vector<string>& tokens) {
    stack<int> s;

    // Scan tokens right to left
    for (int i = tokens.size() - 1; i >= 0; i--) {
        string token = tokens[i];

        if (!isOperator(token)) {
            // Operand (possibly multi-digit)
            s.push(stoi(token));
        } else {
            // Operator
            if (s.size() < 2) {
                cerr << "Invalid expression\n";
                exit(1);
            }
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) {
                    cerr << "Division by zero!\n";
                    exit(1);
                }
                result = a / b;
            }
            else {
                cerr << "Unknown operator: " << token << "\n";
                exit(1);
            }

            s.push(result);
        }
    }

    if (s.size() != 1) {
        cerr << "Invalid expression\n";
        exit(1);
    }

    return s.top();
}

int main() {
    cout << "Enter prefix expression (space separated):\n";
    string line;
    getline(cin, line);

    // Tokenize the input line by spaces
    istringstream iss(line);
    vector<string> tokens;
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    int result = evaluatePrefix(tokens);
    cout << "Result: " << result << "\n";

    return 0;
}
