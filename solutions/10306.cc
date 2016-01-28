#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    while (n--) {

        int m, S;
        cin >> m >> S;
        int SS = S*S;

        vector< pair<int, pair<int, int> > > v(m);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;

            v[i].second.first = a;
            v[i].second.second = b;
            v[i].first = a*a + b*b;
        }

        vector< vector<int> > dp(S+1, vector<int> (S+1, -1));
        dp[0][0] = 0;

        bool found = false;
        int value;
        for (int i = 0; i < m; ++i) {

            int aa = v[i].second.first;
            int bb = v[i].second.second;

            for (int j = 0; j <= S; ++j) {
                for (int k = 0; k <= S; ++k) {

                    if (dp[j][k] != -1) {

                        unsigned long long next_a = (j + aa);
                        unsigned long long next_b = (k + bb);

                        unsigned long long sum = next_a*next_a + next_b*next_b;

                        if (sum == SS) {
                            if (!found) value = dp[j][k] + 1;
                            else if (dp[j][k] + 1 < value) value = dp[j][k] + 1;
                            found = true;
                        }
                        else if (next_a <= S and
                                 next_b <= S and
                                 (dp[next_a][next_b] == -1 or
                                    (dp[next_a][next_b] > (dp[j][k] + 1)))) {
                            dp[next_a][next_b] = dp[j][k] + 1;
                        }
                    }
                }
            }
        }

        if (found) cout << value << endl;
        else cout << "not possible" << endl;
    }
}
