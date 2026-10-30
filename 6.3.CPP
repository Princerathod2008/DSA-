
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main() {
    string infix, postfix = "";
    getline(cin, infix);

    stack<char> st;

    for (char ch : infix) {
        if (ch == ' ')
            continue;

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix: " << postfix;

    return 0;
}
