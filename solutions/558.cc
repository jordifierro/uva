#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {

    int c;
    cin >> c;
    while (c--) {

        int n,m;
        cin >> n >> m;
        vector<int> node(n+1, -1);
        vector<pair < pair<int, int>, int> > edge(m + n);

        for (int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            edge[i] = make_pair(make_pair(x+1, y+1),z);
        }
        for (int i = m; i < m+n; ++i)
            edge[i] = make_pair(make_pair(0, i-m+1), 0);

        node[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < m+n; ++j) {
                if (node[edge[j].first.second] >
                    node[edge[j].first.first] + edge[j].second) {
                        node[edge[j].first.second] =
                            node[edge[j].first.first] + edge[j].second;
                }
            }
        }

        bool cycle_found = false;
        for (int i = 0; i < m+n and !cycle_found; ++i) {
            if (node[edge[i].first.first] <
                node[edge[i].first.second] - edge[i].second)
                    cycle_found = true;
        }

        if(!cycle_found) cout << "not ";
        cout << "possible" << endl;
    }
}
