#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        string s, t;
        ss >> s >> t;

        int x = 0;
        for (int y = 0; x < s.size() and y < t.size(); ++y)
            if (s[x] == t[y]) ++x;

        if (x == s.size()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
