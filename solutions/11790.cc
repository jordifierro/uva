#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

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
    for (int i = 0; i < n; ++i) {

        getline_into(ss);
        int b;
        ss >> b;
        vector< pair<int, int> > v(b);

        getline_into(ss);
        for (int i = 0; i < b; ++i) ss >> v[i].first;

        getline_into(ss);
        for (int i = 0; i < b; ++i) ss >> v[i].second;

        vector< pair<int, unsigned long long> > incr(b);
        vector< pair<int, unsigned long long> > decr(b);
        for (int i = 0; i < b; ++i) {

            incr[i] = v[i];
            decr[i] = v[i];

            for (int j = 0; j < i; ++j) {
                if (incr[j].first < incr[i].first)
                    if (incr[j].second + v[i].second > incr[i].second)
                        incr[i].second = incr[j].second + v[i].second;

                if (decr[j].first > decr[i].first)
                    if (decr[j].second + v[i].second > decr[i].second)
                        decr[i].second = decr[j].second + v[i].second;
            }
        }

        int l_incr = 0;
        int l_decr = 0;
        for (int i = 0; i < b; ++i) {
            if (l_incr < incr[i].second) l_incr = incr[i].second;
            if (l_decr < decr[i].second) l_decr = decr[i].second;
        }

        cout << "Case " << i+1 << ". ";
        if (l_incr >= l_decr)
            cout << "Increasing (" << l_incr << "). Decreasing (" << l_decr;
        else cout << "Decreasing (" << l_decr << "). Increasing (" << l_incr;
        cout  << ")." << endl;
    }
}
