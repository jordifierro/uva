#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MAX 10000

int main() {

    vector<int> v(MAX);
    int max = 0;
    int min = MAX;

    string line;
    getline(cin, line);
    istringstream ss(line);

    int l, h, r;
    while (ss >> l >> h >> r) {

        if (l < min) min = l;
        if (r > max) max = r;

        for (int i = l; i < r; ++i)
            if (h > v[i]) v[i] = h;

        getline(cin, line);
        ss.clear();
        ss.str(line);
    }

    for (int i = min; i < max;) {
        cout << i << " " << v[i] << " ";

        bool change = false;
        for (i++; i < max and !change; ++i) {
            if (v[i-1] != v[i]) {
                change = true;
                --i;
            }
        }
    }
    cout << max << " 0" << endl;
}
