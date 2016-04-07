#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

double dist(const pair<int, int> &p1, const pair<int, int> &p2) {

    int diffx = p1.first - p2.first;
    int diffy = p1.second - p2.second;
    return sqrt(diffx*diffx + diffy*diffy);
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int cases;
    ss >> cases;
    while (cases--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int s, p;
        ss >> s >> p;
        vector< pair<int, int> > v(p);

        for (int i = 0; i < p; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> v[i].first >> v[i].second;
        }

        vector<int> conn(p);
        for (int i = 0; i < p; ++i) conn[i] = i;

        //sort the connections between outposts by distance, minor first
        priority_queue<pair<double, pair<int, int> > > pq;
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                if (i != j)
                    pq.push(make_pair(-dist(v[i], v[j]), make_pair(i,j)));

        //get all the needed connections to connect all outposts
        vector<double> used_conn;
        bool all_conn = false;
        while (!all_conn) {

            pair<double, pair<int, int> > pp = pq.top();
            pq.pop();
            int x = pp.second.first;
            int y = pp.second.second;

            if (conn[x] != conn[y]) {
                used_conn.push_back(-pp.first);

                all_conn = true;
                int old = conn[x];
				int neu = conn[y];
                for (int i = 0; i < p; ++i) {
                    if (conn[i] == old) conn[i] = neu;
                    if (conn[i] != neu) all_conn = false;
                }
            }
        }

        cout << setprecision(2) << fixed << used_conn[p - 1 - s] << endl;
    }
}
