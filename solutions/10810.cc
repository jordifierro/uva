#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

unsigned long long divide_and_count(vector<int> &v, int left, int right) {

    if (right - left == 0) return 0;

    unsigned long long moves_left = divide_and_count(v, left, (left + right)/2);
    unsigned long long moves_right =
                               divide_and_count(v, (left + right)/2 + 1, right);
    unsigned long long moves = moves_left + moves_right;

    int middle = (left + right)/2 + 1;
    int ir = middle;
    int il = left;
    vector<int> aux(right - left + 1);
    int i = 0;
    for (; i < right-left+1  and il < middle and ir <= right; ++i) {
        if (v[il] <= v[ir]) {
            aux[i] = v[il];
            il++;
        } else {
            aux[i] = v[ir];
            ir++;
            moves += middle - il;
        }
    }

    while (il < middle) {
        aux[i] = v[il];
        ++i;
        ++il;
    }
    while (ir <= right) {
        aux[i] = v[ir];
        ++i;
        ++ir;
    }

    for (int j = 0; j < aux.size(); ++j) v[left + j] = aux[j];

    return moves;
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n) {

        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> v[i];
        }

        cout << divide_and_count(v, 0, v.size()-1) << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
