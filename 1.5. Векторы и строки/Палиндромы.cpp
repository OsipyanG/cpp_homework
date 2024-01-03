#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return c == ' '; }), s.end());
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    if (s == reversed_s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}