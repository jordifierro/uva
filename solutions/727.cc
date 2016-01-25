#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main(){

    string line;
    getline(cin, line);
    istringstream ss(line);
    getline(cin, line);

    bool first = true;
    int n;
    ss >> n;
    while (n--) {

        first ? first = false : cout << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);

        stack<char> st;
        char a;
        while (ss >> a) {

            if (a >= '0' and a <= '9') cout << a;
            else if (a == '+' or a == '-') {
                while ( !st.empty() and
                            (st.top() == '+' or
                             st.top() == '-' or
                             st.top() == '*' or
                             st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(a);
            }
            else if (a == '*' or a == '/') {
                while ( !st.empty() and
                        (st.top() == '*' or st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(a);
            }
            else if (a == '(') st.push(a);
            else if (a == ')') {
                while (st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }

            if (!getline(cin, line)) break;
            ss.clear();
            ss.str(line);
        }

        while (!st.empty()) {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}
