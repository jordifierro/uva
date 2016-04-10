#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void travel(const vector<vector<int> > &v, vector<bool> &visited, int node) {

    visited[node] = true;
    for (int i = 0; i < v[node].size(); ++i)
        if (!visited[v[node][i]]) travel(v, visited, v[node][i]);
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int cas = 0;

    int n, m;
    ss >> n >> m;
    while (n or m) {

        vector<vector<int> > v(n);
        for (int i = 0; i < m; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            int a, b;
            ss >> a >> b;
            v[a-1].push_back(b-1);
            v[b-1].push_back(a-1);
        }

        vector<bool> visited(n);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++total;
                travel(v, visited, i);
            }
        }

        cout << "Case " << ++cas << ": " << total << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n >> m;
    }
}
