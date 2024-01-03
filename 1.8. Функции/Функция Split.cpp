#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> Split(const string& str, char delimiter) {
    vector<string> result;
    string token;
    for (char c : str) {
        if (c == delimiter) {
            result.push_back(token);
            token.clear();
        } else {
            token += c;
        }
    }
    result.push_back(token);
    return result;
}
