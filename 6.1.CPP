
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string exp;
    cin >> exp;

    stack<int> st;

    for (char ch : exp) {
        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0');
        } else {
            if (st.size() < 2) {
                cout << "Invalid Expression";
                return 0;
            }

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero";
                        return 0;
                    }
                    st.push(a / b);
                    break;
                default:
                    cout << "Invalid Operator";
                    return 0;
            }
        }
    }

    if (st.size() != 1) {
        cout << "Invalid Expression";
    } else {
        cout << "Result: " << st.top();
    }

    return 0;
}
