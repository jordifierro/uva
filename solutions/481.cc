#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int binary_search(int a, const vector<int> &dp, const vector<int> &v, int max) {

    if(a <= v[dp[1]]) return 1;
    if(a > v[dp[max]]) return max+1;

    int x = 1;
    int y = max;
    while (y-x > 1) {
        int z = (x+y) / 2;
        if(v[dp[z]] >= a) y = z;
        else x = z;
    }
    return y;
}

int main() {

    vector<int> v;
    int a;
    while (cin >> a) v.push_back(a);

    // dp[i] = position on v of the last element of the best seq of length i
    vector<int> dp(v.size()+1);
    vector<int> prev(v.size());
    int max = 1;
    for (int i = 0; i < v.size(); ++i) {
        int dp_i = binary_search(v[i], dp, v, max);
        if(dp_i > max) max = dp_i;
        prev[i] = dp[dp_i-1];
        dp[dp_i] = i;
    }

    string o;
    ostringstream os;
    int i = max;
    int pos_i = dp[max];
    while (i--) {
        os.str("");
        os << v[pos_i] << endl;
        o = os.str() + o;
        pos_i = prev[pos_i];
    }

    cout << max << endl << "-" << endl << o;
}
