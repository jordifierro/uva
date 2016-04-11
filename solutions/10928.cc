#include <iostream>
#include <vector>
#include <sstream>

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

        int p;
        ss >> p;
        vector<int> kns(p);

        int min_kns = p+1;

        for (int i = 0; i < p; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);

            int ignore;
            while (ss >> ignore) ++kns[i];
            if (kns[i] < min_kns) min_kns = kns[i];
        }

        bool first = true;
        for (int i = 0; i < p; ++i) {
            if (kns[i] == min_kns) {
                first ? first = false : cout << " ";
                cout << i+1;
            }
        }
        cout << endl;

        getline(cin, line);
    }
}
