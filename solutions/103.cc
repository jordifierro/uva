#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool fits_in(const vector<int> &a, const vector<int> &b) {

    for (int i = 0; i < a.size(); ++i)
        if(a[i] >= b[i]) return false;

    return true;
}


int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int k, n;
    while (ss >> k >> n) {

        vector< pair<vector<int>, int> > v(k, make_pair(vector<int> (n), 0));

        for (int i = 0; i < k; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);
            for (int j = 0; j < n; ++j)	ss >> v[i].first[j];

            //save element index befor sort
            v[i].second = i;
            sort(v[i].first.begin(), v[i].first.end());
        }

        //after this sort, if v[d] fits in v[e] then d > e
        sort(v.begin(), v.end());

        //dp table vector(previous_element, total_lenght)
        vector< pair<int, int> > dp(k, make_pair(-1,1));
        int max_value = 0;
        int max_index = 0;

        //dp[i] = max(0, ∀j | fits_in(v[j], v[i]): dp[j] + 1)
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j].second + 1 > dp[i].second and
                    fits_in(v[j].first, v[i].first)) {

                    dp[i].second = dp[j].second + 1; //total_lenght
                    dp[i].first = j; //previous_element

                    if (dp[i].second > max_value) { //longest subsequence
                        max_value = dp[i].second;
                        max_index = i;
                    }
                }
            }
        }

        //last element
        ostringstream sss;
        sss << v[max_index].second + 1;
        string output = sss.str();
        
        //iterate back
        int prev = dp[max_index].first;
        while (prev != -1) {
            sss.clear();
            sss.str("");
            sss << v[prev].second + 1 << " ";
            output = sss.str() + output;
            prev = dp[prev].first;
        }

        cout << dp[max_index].second << endl;
        cout << output << endl;

        if (!getline(cin, line)) break;
        ss.clear();
        ss.str(line);
    }
}
