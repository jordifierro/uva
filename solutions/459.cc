#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void tour(  const vector< vector<int> > &graph,
            vector<bool> &visited, int current) {

    visited[current] = true;
    for (int i = 0; i < graph[current].size(); ++i) {

        int next = graph[current][i];
        if (!visited[next]) tour(graph, visited, next);
    }
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);
    getline(cin, line);

    int n;
    ss >> n;
    while (n--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        char a;
        ss >> a;
        int m = a - 'A' + 1;

        vector< vector<int> > graph(m);

        bool stop = false;
        while (!stop) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            string node;
            if (ss >> node) {
                graph[node[0] - 'A'].push_back(node[1] - 'A');
                graph[node[1] - 'A'].push_back(node[0] - 'A');
            }
            else stop = true;
        }

        vector<bool> visited(m);
        int counter = 0;
        for (int i = 0; i < m; ++i) {
            if (!visited[i]) {
                counter++;
                tour(graph, visited, i);
            }
        }

        cout << counter << endl;
        if (n) cout << endl;
    }
}
