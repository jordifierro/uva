#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void swap(vector<int> &v, int i, int j) {
    v[i] ^= v[j];
    v[j] ^= v[i];
    v[i] ^= v[j];
}

int bubble(vector<int> &v) {

    if (v.size() == 0 or v.size() == 1) return 0;

    int moves = 0;
    for (int i = 0; i < v.size()-1; ++i) {
        for (int j = v.size()-1; j > i; --j) {
            if (v[j] < v[j-1]) {
                swap(v, j, j-1);
                ++moves;
            }
        }
    }
    return moves;
}

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
        int l;
        ss >> l;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        vector<int> t(l);
        for (int i = 0; i < l; ++i) ss >> t[i];

        cout << "Optimal train swapping takes " << bubble(t) << " swaps." << endl;
    }
}
