#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define H5 5*60*60

void print_hour(int n) {

    cout << setfill('0') << setw(2) << n/3600 << ":";
    cout << setfill('0') << setw(2) << (n/60)%60 << ":";
    cout << setfill('0') << setw(2) << n%60 << endl;
}

int main() {

    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    while (v[0] or v[1] or v[2]) {

        while (v[v.size()-1]) {
            int n;
            cin >> n;
            v.push_back(n);
        }

        vector<bool> g(H5, true);
        int first_orange = v[0];
        for (int i = 0; i < v.size()-1; ++i) {
            int orange = v[i] - 5;
            if (first_orange > orange) first_orange = orange;
            while (orange <= H5) {
                for (int j = orange; j <= H5 and j < orange + v[i] + 5; ++j)
                    g[j] = false;

                orange += 2*v[i];
            }
        }

        bool sync = false;
        for (int i = first_orange; i <= H5 and !sync; ++i) {
            if (g[i]) {
                print_hour(i);
                sync = true;
            }
        }
        if (!sync) cout << "Signals fail to synchronise in 5 hours" << endl;

        v = vector<int> (3);
        cin >> v[0] >> v[1] >> v[2];
    }
}
