#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MAX 10000

void getline_into(istringstream& ss) {

    string line;
    getline(cin, line);
    ss.clear();
    ss.str(line);
}

int main() {

    istringstream ss;

    getline_into(ss);
    int n;
    ss >> n;
    while (n--) {

        getline_into(ss);
        int price;
        ss >> price;

        getline_into(ss);
        int m;
        ss >> m;
        vector<int> v(m);

        for (int i = 0; i < m; ++i) {
            getline_into(ss);
            ss >> v[i];
        }

        vector<int> dp(MAX*2+1, -1);
        dp[0] = 0;

        for (int i = 0; i < m; ++i) {
            int curr = v[i];
            for (int j = MAX*2 - curr; j >= 0; --j)
                if (dp[j] != -1)
                    if(dp[j+curr] == -1 or (dp[j+curr] > dp[j]+1))
                        dp[j+curr] = dp[j]+1;
        }

        bool found = false;
        for (int i = price; i <= MAX*2 and !found; ++i) {
            if (dp[i] != -1) {
                found = true;
                cout << i << " " << dp[i] << endl;
            }
        }
        if (!found) cout << "error" << endl;
    }
}
