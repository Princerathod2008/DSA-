
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) {
                cout << "No";
                return 0;
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                cout << "No";
                return 0;
            }
        }
    }

    if (st.empty())
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
