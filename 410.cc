#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    string line;
    int cases = 0;
    int c, s;
    while (cin >> c >> s) {

        vector<int> v(2*c);
        long double total_mass = 0;
        for (int i = 0; i < s; ++i) {
            cin >> v[i];
            total_mass += v[i];
        }

        sort(v.begin(), v.end());

        long double avg_mass = total_mass / c;
        long double imbalance = 0;

        cout << "Set #" << ++cases << endl;
        for (int i = 0; i < c; ++i) {
            int i_inverse = 2*c - 1 - i;
            imbalance += fabs(v[i] + v[i_inverse] - avg_mass);

            cout << " " << i << ":";
            if (v[i]) cout << " " << v[i];
            if (v[i_inverse]) cout << " " << v[i_inverse];
            cout << endl;
        }
        cout << "IMBALANCE = " << setprecision(5) << fixed << imbalance << endl << endl;
    }
}
