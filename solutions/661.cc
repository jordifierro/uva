#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int seq = 0;
    int n, m, c;
    ss >> n >> m >> c;
    while (n or m or c) {

        vector<int> amp(n);
        vector<bool> state(n);

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> amp[i];
        }

        long max = 0;
        long current = 0;
        bool blow = false;

        for (int i = 0; i < m; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            int e;
            ss >> e;

            if (!blow) {
                current += (1 - 2*state[e-1]) * amp[e-1];
                state[e-1] = !state[e-1];

                if(max < current) max = current;
                if(max > c) blow = true;
            }
        }

        cout << "Sequence " << ++seq << endl;
        if (blow) cout << "Fuse was blown.";
        else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << max << " amperes.";
        }
        cout << endl << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n >> m >> c;
    }
}
