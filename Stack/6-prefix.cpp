#include <iostream>
#include <stack>
using namespace std;

int func(string& exp) {
    stack<int> s;
    int n = exp.length();
    for (int i = n-1; i >= 0; i--) {
        char c = exp[i];
        if (c == ' ') {
            continue;
        } else if (c != '+' && c != '-' && c != '*' && c != '/') {
            s.push(c - '0');
        } else {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            int res;
            if (c == '+') {
                res = op1 + op2;
            } else if (c == '-') {
                res = op2 - op1;
            } else if (c == '*') {
                res = op1 * op2;
            } else {
                res = op2 / op1;
            }
            s.push(res);
        }
    }
    return s.top();
}

int main() {
    string exp;
    getline(cin, exp);
    int res = func(exp);
    cout << res << endl;

    return 0;
}