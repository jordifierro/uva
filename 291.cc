#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void hamiltonian(   const vector<vector<int> > &v,
                    int current, string path, vector<bool> &visited){

        if (path.size() == 9) cout << path << endl;
        else {

            for (int i = 0; i < v[current].size(); ++i) {

                int hash = current * v[current][i];
                if (!visited[hash]) {

                    ostringstream oss;
                    oss << path << v[current][i];
                    string newpath = oss.str();

                    visited[hash] = true;
                    hamiltonian(v, v[current][i], newpath, visited);
                    visited[hash] = false;
                }
            }
        }
    }

    int main() {

        vector< vector<int> > graph(6);
        graph[1].push_back(2);
        graph[1].push_back(3);
        graph[1].push_back(5);

        graph[2].push_back(1);
        graph[2].push_back(3);
        graph[2].push_back(5);

        graph[3].push_back(1);
        graph[3].push_back(2);
        graph[3].push_back(4);
        graph[3].push_back(5);

        graph[4].push_back(3);
        graph[4].push_back(5);

        graph[5].push_back(1);
        graph[5].push_back(2);
        graph[5].push_back(3);
        graph[5].push_back(4);

        vector<bool> visited(5*4);
        hamiltonian(graph, 1, "1", visited);
    }
