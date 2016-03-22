#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        int n, k;
        ss >> n >> k;

        long total = n;
        int butts = n;
        while (butts >= k) {
            total += butts / k;
            butts = butts / k + butts % k;
        }

        cout << total << endl;
    }
}
