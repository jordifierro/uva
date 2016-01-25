#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);
    getline(cin, line);

    int cases;
    ss >> cases;
    while (cases--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);
        int n;
        ss >> n;

        vector<int> v(n+1);
        for (int i = 0; i < n+1; ++i) v[i] = i;
        int correct = 0;
        int error = 0;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        char a;
        int b, c;
        while (ss >> a >> b >> c) {

            if(a == 'c') {
                int old, neu;
                if (v[b] != v[c]) {
                    old = max(v[c], v[b]);
                    neu = min(v[c], v[b]);
                    for (int i = 0; i < n+1; ++i)
                        if(v[i] == old) v[i] = neu;
                }
            } else if(a == 'q') {
                if (v[c] == v[b]) correct++;
                else error++;
            }

            if(!getline(cin, line)) break;
            ss.clear();
            ss.str(line);
        }

        cout << correct << "," << error << endl;
        if(cases) cout << endl;
    }
}
