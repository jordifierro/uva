#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    bool first = true;
    int c;
    ss >> c;
    while (c--) {

        first ? first = false : cout << endl;

        getline(cin, line);
        getline(cin, line);
        ss.clear();
        ss.str(line);
        int n;
        ss >> n;

        vector<double> transparency(n);
        vector< pair<double, pair<int, bool> > > marks;

        for (int i = 0; i < n; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);
            double a, b, c, d, e;
            ss >> a >> b >> c >> d >> e;

            if (c < a) {
                double t = a;
                a = c;
                c = t;
            }
            marks.push_back(make_pair(a, make_pair(i, true)));
            marks.push_back(make_pair(c, make_pair(i, false)));
            transparency[i] = e;
        }

        sort(marks.begin(), marks.end());
        cout << marks.size()+1 << endl;

        cout.precision(3);

        double last = -1;
        set<int> s;
        for (int i = 0; i < marks.size(); ++i) {

            double count = 1;
            set<int>::iterator it;
            for (it = s.begin(); it != s.end(); ++it)
            count *= transparency[*it];

            if (last > -1.f) cout << fixed << last;
            else cout << "-inf";
            cout << " " << fixed << marks[i].first << " ";
            cout << fixed << count << endl;

            if (marks[i].second.second) s.insert(marks[i].second.first);
            else s.erase(marks[i].second.first);
            last = marks[i].first;
        }

        cout << fixed << last << " " << "+inf 1.000" << endl;
    }
}
