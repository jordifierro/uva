#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int cut(const vector<int> &v, vector< vector<int> > &dp,
        int l, int i, int j, int ini, int fi) {

    if (i < 0) return 0;
    if (j >= v.size()) return 0;
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return (dp[i][j] = l);

    int min = l*l;
    for (int k = i; k <= j; ++k) {
        int current = l + cut(v, dp, v[k]-ini, i, k-1, ini, v[k]) +
                          cut(v, dp, fi-v[k], k+1, j, v[k], fi);
        if (current < min) min = current;
    }
    return (dp[i][j] = min);
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int l;
    ss >> l;
    while (l) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int n;
        ss >> n;
        vector<int> v(n+2);

        getline(cin, line);
        ss.clear();
        ss.str(line);
        for (int i = 0; i < n; ++i) ss >> v[i];

        vector< vector<int> > dp(n, vector<int> (n, -1));

        if (n) {
            cut(v, dp, l, 0, n-1, 0, l);
            cout << "The minimum cutting is " << dp[0][n-1] << "." << endl;
        }
        else cout << "The minimum cutting is 0." << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> l;
    }
}
