#include <iostream>
#include <stack>
using namespace std;

bool func(string& str) {
    stack<char> s;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (s.empty()) return false;
            else {
                if ((s.top() == '(' && str[i] == ')') || (s.top() == '{' && str[i] == '}') || (s.top() == '[' && str[i] == ']')) {
                    s.pop();
                } else return false;
            }
        } 
    }
    return s.empty() ? true : false;
}

int main() {
    string str;
    getline(cin, str);
    bool res = func(str);
    cout << (res == 1 ? "true" : "false") << endl;

    return 0;
}