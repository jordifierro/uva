#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {

    bool firstcase = true;

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        int n;
        ss >> n;
        vector<string> v(n);

        getline(cin, line);
        ss.clear();
        ss.str(line);
        for (int i = 0; i < n; ++i) ss >> v[i];

        map<string, int> m;
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);

            string person;
            int money, receivers;
            ss >> person >> money >> receivers;

            if (receivers) {
                int part = money/receivers;
                m[person] -= receivers * part;

                for (int j = 0; j < receivers; ++j) {
                    ss >> person;
                    m[person] += part;
                }
            }
        }

        (firstcase ? firstcase = false : cout << endl);
        for (int i = 0; i < n; ++i)
            cout << v[i] << " " << m[v[i]] << endl;
    }
}
