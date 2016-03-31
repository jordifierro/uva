#include <iostream>
#include <vector>

using namespace std;

bool square(const vector<int> &v, vector<bool> &valid,
            int sum, int curr_side, int bitmask) {

    if (!valid[bitmask]) return false;
    if (curr_side > sum/4) return false;
    if (curr_side == sum/4) {
        if (bitmask == (1 << v.size()) - 1) return true;
        curr_side = 0;
    }
    for (int i = 0; i < v.size(); ++i)
        if (!(bitmask & 1 << i) and
            square(v, valid, sum, curr_side + v[i], bitmask | 1 << i ))
            return true;

    return valid[bitmask] = false;
}

int main() {

    int n;
    cin >> n;
    while (n--) {

        int m;
        cin >> m;
        vector<int> v(m);

        int sum = 0;
        for (int i = 0; i < m; ++i) {
            cin >> v[i];
            sum += v[i];
        }

        if (sum % 4) cout << "no" << endl;
        else {
            vector<bool> valid(1 << m, true);
            if (square(v, valid, sum, 0, 0)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}
