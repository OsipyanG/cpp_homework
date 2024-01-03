#include <iostream>
#include <stack>
#include <string>
using namespace std;

long long precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

long long applyOp(long long a, long long b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

long long evaluate(string tokens) {
    int i;

    stack<long long> values;

    stack<char> ops;

    for (i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ')
            continue;

        else if (isdigit(tokens[i])) {
            long long val = 0;

            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(val);
            i--;
        }

        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                long long val2 = values.top();
                values.pop();

                long long val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while (!ops.empty()) {
        long long val2 = values.top();
        values.pop();

        long long val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    cout << evaluate(input) << "\n";
    return 0;
}