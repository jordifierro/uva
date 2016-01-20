#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int cases;
    ss >> cases;
    while (cases--) {

        getline(cin, line);
        getline(cin, line);
        ss.clear();
        ss.str(line);
        int n, t, m;
        ss >> n >> t >> m;

        vector<int> v(n);
        getline(cin, line);
        ss.clear();
        ss.str(line);
        for (int i = 0; i < n; ++i) {
            ss >> v[i];
            char a;
            if(i < n-1) ss >> a;
        }

        int max = 0;
        vector<int> dp(m*(t+1), -1);
        for (int i = 0; i < m; ++i) dp[i*(t+1)] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int max_bloc = 0;
                for (int k = t; k >= 0; --k) {

                    if (dp[j*(t+1) + k] != -1) {
                        if (dp[j*(t+1) + k] > max_bloc) {
                            max_bloc = dp[j*(t+1) + k];
                            if( j+1 < m and dp[(j+1) * (t+1)] < max_bloc)
                                dp[(j+1)*(t+1)] = max_bloc;
                        }
                        if (k <= t-v[i] and
                              (dp[j*(t+1) + k + v[i]] == -1 or
                               dp[j*(t+1) + k + v[i]] <  dp[j*(t+1) + k] + 1)) {
                                   dp[j*(t+1) + k + v[i]] = dp[j*(t+1) + k] + 1;
                        }
                    }
                    if (k <= t-v[i] and
                        dp[j*(t+1) + k + v[i]] > max) {
                            max = dp[j*(t+1) + k + v[i]];
                    }
                }
            }
        }

        cout << max << endl;
        if(cases) cout << endl;

    }
}
