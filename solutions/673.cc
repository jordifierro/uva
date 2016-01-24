#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        stack<char> st;
        bool correct = true;
        char current;
        for (int i = 0; ss >> current and correct; ++i) {

            if (current == '(') st.push('(');
            else if (current == '[') st.push('[');
            else if (current == ')') {
                if(st.size() == 0) correct = false;
                else {
                    char a = st.top(); st.pop();
                    if (a != '(') correct = false;
                }
            }
            else if (current == ']') {
                if (st.size() == 0) correct = false;
                else {
                    char a = st.top(); st.pop();
                    if(a != '[') correct = false;
                }
            }
        }

        if (correct and st.size() == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
