#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#define WELLINGTON 12

bool well(int m, int n) {

    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;

    int i = 0;
    while (v.size()) {
        if (v[i] == WELLINGTON) break;
        v.erase(v.begin() + i);
        i = (i + m - 1) % v.size();
    }

    return v.size() == 1;
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n) {

        for (int m = 1; m < n*n; ++m) {
            if (well(m, n)) {
                cout << m << endl;
                break;
            }
        }

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
