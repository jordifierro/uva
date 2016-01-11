#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        int n;
        ss >> n;

        vector< vector< vector<double> > > fw(n,
            vector< vector<double> > (n, vector<double> (n)));
        vector< vector< vector<int> > > track(n,
            vector< vector<int> > (n, vector<int> (n)));
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);

            for (int j = 0; j < n; ++j) {
                if(i == j) fw[0][i][j] = 1.0;
                else ss >> fw[0][i][j];
                track[0][i][j] = i;
            }
        }

        //Floyd-Warshall algorithm
        bool found = false;
        int when;
        for (int c = 1; c < n and !found; ++c) {
            for (int k = 0; k < n and !found; ++k) {
                for (int i = 0; i < n and !found; ++i) {
                    for (int j = 0; j < n and !found; ++j) {

                        double ratio = fw[c-1][i][k] * fw[0][k][j];
                        if (ratio > fw[c][i][j]) {
                            fw[c][i][j] = ratio;
                            track[c][i][j] = k;
                            if(i == j and ratio > 1.01) {
                                found = true;
                                when = c;
                            }
                        }
                    }
                }
            }
        }

        if (found) {
            bool done = false;
            vector<int> solution;
            for (int i = 0; i < n and !done; ++i) {

                if (fw[when][i][i] > 1.01f) {
                    solution = vector<int> (when+1);
                    solution[when] = track[when][i][i];
                    for (int j = when-1; j >= 0; --j) {
                        solution[j] = track[j][i][solution[j+1]];
                    }
                    done = true;
                }
            }

            for (int i = 0; i < solution.size(); ++i)
                cout << solution[i] + 1 << " ";
            cout << solution[0] + 1 << endl;
        } else cout << "no arbitrage sequence exists" << endl;
    }
}
