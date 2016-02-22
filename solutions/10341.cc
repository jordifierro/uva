#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cmath>

#define EPS 1e-7

using namespace std;

double calc(int p, int q, int r, int s, int t, int u, double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        double x;
        int p, q, r, s, t, u;
        ss >> p >> q >> r >> s >> t >> u;

        double zero = calc(p, q, r, s, t, u, 0);
        double one = calc(p, q, r, s, t, u, 1);

        if ((zero < 0 and one < 0) or (zero > 0 and one > 0)) {
            cout << "No solution" << endl;
        }
        else if (zero == 0) {
            cout << "0.0000" << endl;
        }
        else if (one == 0) {
            cout << "1.0000" << endl;
        }
        else {
            double lo = 0;
            double hi = 1;
            while (lo + EPS < hi) {
                x = (lo + hi) / 2;
                if (calc(p, q, r, s, t, u,lo) *
                    calc(p, q, r, s, t, u,x) <= 0) hi = x;
                else lo = x;
            }
            x = (lo + hi) / 2;

            cout << setprecision(4) << fixed << x << endl;
        }
    }
}
