#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;

    vector< vector<int> > v(n, vector<int> (n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> v[i][j];

    vector< vector<int> > dp(n, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        dp[0][i] = v[0][i];
        for (int j = 1; j < n; ++j)
            dp[j][i] = dp[j-1][i] + v[j][i];
    }

    int max_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += dp[j][k] - (i-1 >= 0 ? dp[i-1][k]:0);
                if (sum > max_sum) max_sum = sum;
                if (sum < 0) sum = 0;
            }
        }
    }

    cout << max_sum << endl;
}
