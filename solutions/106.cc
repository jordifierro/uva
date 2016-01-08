#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {

    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        int n;
        ss >> n;

        vector<bool> used(n + 1);
        int nn = sqrt(n);
        int prime_triples = 0;

        //check this to understand the trick:
        //  http://www.algorithmist.com/index.php/UVa_106
        for (int s = 1; s <= nn; ++s) {
            for (int r = s+1; r <= nn; ++r) {
                int rr = r*r;
                int ss = s*s;
                int x = rr - ss;
                int y = 2*r*s;
                int z = rr + ss;

                for (int k = 1; k * z <= n; k++) {
					used[k*x] = true;
					used[k*y] = true;
					used[k*z] = true;
				}
                if (z <= n and (r&0x01 xor s&0x01) and gcd(r, s) == 1)
                    ++prime_triples;
            }
        }

        int unused = 0;
        for (int i = 1; i <= n; ++i) if(!used[i]) ++unused;

        cout << prime_triples << " " << unused << endl;
    }
}
