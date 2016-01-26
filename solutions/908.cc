#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    bool first = true;
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        int comps;
        ss >> comps;

        vector<int> v(comps);
        for (int i = 0; i < comps; ++i)	v[i] = i;

        priority_queue< pair<int, pair<int, int> > > pq;
        unsigned long long int oldcost = 0;

        for (int i = 0; i < comps-1; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);

            int a, b, c;
            ss >> a >> b >> c;
            a--;
            b--;

            pq.push(make_pair(-c, make_pair(a,b)));
            oldcost += c;
        }

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int k;
        ss >> k;
        for (int i = 0; i < k; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);

            int a, b, c;
            ss >> a >> b >> c;
            a--;
            b--;

            pq.push(make_pair(-c, make_pair(a,b)));
        }

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int m;
        ss >> m;
        for (int i = 0; i < m; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);

            int a, b, c;
            ss >> a >> b >> c;
            a--;
            b--;

            pq.push(make_pair(-c, make_pair(a,b)));
        }

        bool complet = false;
        unsigned long long int newcost = 0;
        for (int i = 0; !complet; ++i) {
            pair< int, pair<int, int> > p = pq.top();
            pq.pop();

            int old, neu, oa, ob;
            oa = p.second.first;
            ob = p.second.second;
            if (v[oa] != v[ob]) {

                newcost += -p.first;
                old = max(v[oa], v[ob]);
                neu = min(v[oa], v[ob]);

                bool igual = true;
                for (int i = 0; i < comps; ++i) {
                    if (v[i] == old) v[i] = neu;
                    if (i and v[i] != v[i-1]) igual = false;
                }
                if (igual) complet = true;
            }
        }

        first ? first = false : cout << endl;

        cout << oldcost << endl;
        cout << newcost << endl;

        if (!getline(cin, line)) break;
    }
}
