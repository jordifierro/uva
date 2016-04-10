#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

#define MAX 1000000000000L

vector<unsigned long long> almoprimes;

bool is_prime(long long n) {
    for (int i = 3; i <= sqrt(n); i += 2) if (n % i == 0) return false;
    return true;
}

void generate_almoprimes(unsigned long long n) {
    for (unsigned long long i = n*n; i < MAX; i *= n) almoprimes.push_back(i);
}

void precalc_almoprimes() {
    generate_almoprimes(2);
    for (int i = 3; i <= sqrt(MAX); i += 2)
        if (is_prime(i)) generate_almoprimes(i);
}

int main() {

    precalc_almoprimes();

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        unsigned long long a, b;
        ss >> a >> b;

        int almo_sum = 0;
        for (int i = 0; i < almoprimes.size(); ++i) {
            if (almoprimes[i] >= a and almoprimes[i] <= b) ++almo_sum;
        }
        cout << almo_sum << endl;
    }
}
