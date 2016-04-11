#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n, m;
    ss >> n >> m;
    while (n or m) {

        vector<int> heads(n);
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> heads[i];
        }

        vector<int> knights(m);
        for (int i = 0; i < m; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> knights[i];
        }

        if (m >= n) {
            sort(heads.begin(), heads.end());
            sort(knights.begin(), knights.end());

            unsigned long long cost = 0;
            int hi = 0;
            for (int ki = 0; ki < m and hi < n; ++ki) {
                if (knights[ki] >= heads[hi]) {
                    ++hi;
                    cost += knights[ki];
                }
            }
            if (hi == n) cout << cost << endl;
            else cout << "Loowater is doomed!" << endl;
        }
        else cout << "Loowater is doomed!" << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n >> m;
    }
}
