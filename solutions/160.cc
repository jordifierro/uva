#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<int> create_cribe() {

    vector<int> primes;
    vector<bool> p(101);
    for (int i = 3; i <= p.size()/2 + 1; i += 2)
        if (!p[i])
            for (int j = i+i; j < p.size(); j += i) p[j] = true;

    primes.push_back(2);
    for (int i = 3; i < p.size(); i += 2)
        if (!p[i]) primes.push_back(i);

    return primes;
}

int main() {

    vector<int> primes = create_cribe();

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n) {

        vector<int> times(primes.size());
        int last = 0;
        for (int i = 2; i <= n; ++i) {
            int current = i;
            int prime = 0;
            while (current > 1) {
                if (current%primes[prime] == 0) {
                    current /= primes[prime];
                    ++times[prime];
                    if (last < prime) last = prime;
                } else ++prime;
            }
        }

        cout << setw(3) << n << "! =";
        for (int i = 0; i <= last; ++i) {
            if (i and i%15 == 0) cout << endl << "      ";
            cout << setw(3) << times[i];
        }
        cout << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
