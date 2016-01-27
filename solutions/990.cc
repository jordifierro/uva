#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    bool first = true;

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);
        int t, w;
        ss >> t >> w;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        int n;
        ss >> n;

        vector< pair<int, int> > v(n);
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> v[i].first >> v[i].second;
            v[i].first = v[i].first * 3 * w;
        }

        vector< vector< pair<long, pair<int, int> > > >dp(n+1,
                    vector<pair<long, pair<int, int> > > (t+1,
                        make_pair(-1, make_pair(-1, -1))));
        dp[0][0].first = 0;
        for (int j = 0; j < n; ++j) {
            long ii = v[j].first;
            for (int k = 0; k < t+1; ++k) dp[j+1][k] = dp[j][k];
            for (int k = t-ii; k >= 0; --k) {
                if (dp[j][k].first != -1) {
                    if ( dp[j+1][k+ii].first == -1 or
                        (dp[j+1][k+ii].first < dp[j][k].first + v[j].second)) {

                            dp[j+1][k+ii].first = dp[j][k].first + v[j].second;
                            dp[j+1][k+ii].second.first = j;
                            dp[j+1][k+ii].second.second = dp[j][k].second.first;
                    }
                }
            }
        }

        long max = 0;
        int posx = 0;
        int posy  = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < t+1; ++j) {
                if (dp[i][j].first > max) {
                    max = dp[i][j].first;
                    posx = i;
                    posy = j;
                }
            }
        }

        first ? first = false : cout << endl;
        cout << max << endl;

        ostringstream sss;
        string ou = "";
        int total = 0;
        int j = posy;
        for (int i = posx;  dp[i][j].second.first != -1 and
                            i >= 0 and
                            j >= 0;) {

            sss << v[dp[i][j].second.first].first / (3*w) << " ";
            sss << v[dp[i][j].second.first].second << endl;
            ou = sss.str() + ou;
            ss.clear();
            sss.str("");
            int nexti = dp[i][j].second.second + 1;
            j -= v[dp[i][j].second.first].first;
            i = nexti;
            ++total;
        }
        cout << total << endl;
        cout << ou;

        if (!(getline(cin, line))) break;
    }
}
