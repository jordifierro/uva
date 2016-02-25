#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

#define MAX numeric_limits<int>::max()/2

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);
    getline(cin, line);

    int cases;
    ss >> cases;
    while (cases--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int dist;
        ss >> dist;
        dist /= 100;

        vector<vector<int> > v;

        while (getline(cin, line)) {
            ss.clear();
            ss.str(line);

            vector<int> v_aux(dist);

            int aux;
            if (ss >> aux) {
                for (int j = 0; j < dist; ++j) {
                    v_aux[j] = aux;
                    ss >> aux;
                }
            } else break;

            v.push_back(v_aux);
        }
        reverse(v.begin(), v.end());

        int n = v.size();
        vector<vector<unsigned int> > dp(n, vector<unsigned int> (dist, MAX));
        dp[0][0] = 30 - v[0][0];
        dp[1][0] = 60 - v[0][0];

        for (int j = 1; j < dist; ++j)
            for (int i = 0; i < n; ++i)
                dp[i][j] =
                    min((i+1 < n ? dp[i+1][j-1] + 20 - v[i+1][j] : MAX),
                        min(dp[i][j-1] + 30 - v[i][j],
                            (i-1 >= 0 ? dp[i-1][j-1] + 60 - v[i-1][j] : MAX) ));

        cout << dp[0][dist-1] << endl << endl;
    }
}
