#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    bool first = true;
    int n;
    ss >> n;
    while (n) {

        bool second = true;
        bool finish = false;
        while (!finish) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            stack<int> st;
            int k = 0;

            vector<int> v(n);
            for (int i = 0; i < n and !finish; ++i) {
                ss >> v[i];
                if(v[i] == 0) finish = true;
            }

            for (int i = 0; i < n and !finish; ++i) {
                if (v[k] != i+1) st.push(i+1);
                else ++k;

                while (!st.empty() and st.top() == v[k]) {
                    st.pop();
                    ++k;
                }
            }
            if (!finish) {
                if (second) second = false;

                if (st.empty()) cout << "Yes";
                else cout << "No";
                cout << endl;
            }
            if (finish and !second) cout << endl;
        }

        if (first and !second) first = false;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
