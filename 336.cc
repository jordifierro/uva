#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

int bfs(int start, int max_length,
        const vector< vector<int> > &graph,
        vector<bool> &reached) {

    int non_reached_nodes = graph.size();

    //queue of (node, accumulated_lenght)
    queue< pair<int, int> > q;
    q.push(make_pair(start, 0));

    while (!q.empty()) {

        pair<int, int> curr = q.front();
        q.pop();

        if (!reached[curr.first]) {
            reached[curr.first] = true;
            non_reached_nodes--;

            if (curr.second < max_length)
                for (int i = 0; i < graph[curr.first].size(); ++i)
                    q.push(make_pair(graph[curr.first][i], curr.second + 1));
        }
    }

    return non_reached_nodes;
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int cases = 0;

    int n;
    ss >> n;
    while (n) {

        map<int, int> hash;
        vector< vector<int> > graph;
        int index_gr = 0;

        int elems = 0;
        while (elems < n) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            int a, b;
            while (ss >> a >> b) {

                if (hash.find(a) == hash.end()) {
                    hash[a] = index_gr;
                    graph.push_back(vector<int> ());
                    index_gr++;
                }
                if (hash.find(b) == hash.end()) {
                    hash[b] = index_gr;
                    graph.push_back(vector<int> ());
                    index_gr++;
                }

                graph[hash[a]].push_back(hash[b]);
                graph[hash[b]].push_back(hash[a]);
                ++elems;
            }
        }

        bool stop = false;
        while (!stop and getline(cin, line)) {

            ss.clear();
            ss.str(line);
            int start, ttl;
            while (!stop and ss >> start >> ttl) {

                if (!(start or ttl)) stop = true;
                else {
                    cout << "Case " << (++cases) << ": ";

                    vector<bool> reached(graph.size());
                    cout << bfs(hash[start], ttl, graph, reached);

                    cout << " nodes not reachable from node " << start;
                    cout << " with TTL = " << ttl << "." << endl;
                }
            }
        }

        getline(cin, line);
        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
