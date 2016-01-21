#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        int n;
        ss >> n;

        int half = pow(10, n/2);
        for (int i = 0; i < half; ++i) {
            int squared = i*i;
            if (squared/half + squared%half == i)
                cout << setfill('0') << setw(n) << squared << endl;
        }
    }
}
