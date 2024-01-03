#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatching(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else
        return false;
}

bool isBalanced(string sequence) {
    stack<char> st;
    for (char ch : sequence) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty() || !isMatching(st.top(), ch)) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    string sequence;
    cin >> sequence;

    if (isBalanced(sequence)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}