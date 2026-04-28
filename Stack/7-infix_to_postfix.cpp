#include <iostream>
#include <stack>
#include <string>
using namespace std;

int func1(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string func(string& str) {
    stack<char> s;
    string res;
    for (char c : str) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                res.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!s.empty() && s.top() != '(' && func1(s.top()) >= func1(c)) {
                res.push_back(s.top());
                s.pop();
            }
            s.push(c);
        } else {
            res.push_back(c);
        }
    }

    while (!s.empty()) {
        char x = s.top();
        if (x == ')' || x == '(') {
            s.pop();
            continue;
        }
        res.push_back(x);
        s.pop();
    }

    return res;
}

int main() {
    string str;
    getline(cin, str);
    string res = func(str);
    cout << res << endl;

    return 0;
}