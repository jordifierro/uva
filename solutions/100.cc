#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MAX_DP 1000000

void swap(int &i, int &j) {
    i ^= j;
    j ^= i;
    i ^= j;
}

int calculate(vector<int> &dp, unsigned int i) {

    if (i < MAX_DP) {
        if (dp[i]) return dp[i];
        else if (i & 0x01) return dp[i] = calculate(dp, 3*i + 1) + 1;
        else return dp[i] = calculate(dp, i/2) + 1;
    }
    else {
        if (i & 0x01) return calculate(dp, 3*i + 1) + 1;
        else return calculate(dp, i/2) + 1;
    }
}

int main() {

    vector<int> dp(MAX_DP);
    dp[1] = 1;

	string line;
	while (getline(cin, line)) {
        istringstream ss(line);

        int i, j;
        ss >> i >> j;
        cout << i << " " << j << " ";

        if (i > j) swap(i, j);

        int max = 0;
        for (int k = i; k <= j; ++k) {
            if (dp[k] == 0) calculate(dp, k);
            if (dp[k] > max) max = dp[k];
        }
        cout << max << endl;
    }
}
