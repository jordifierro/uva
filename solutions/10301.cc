#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

bool intersect( const vector< pair< float, pair<float, float> > > &v,
                int i, int j) {

    float dx = v[i].second.first - v[j].second.first;
    float dy = v[i].second.second - v[j].second.second;
    float distance = sqrt(dx*dx + dy*dy);
    double sum = v[i].first + v[j].first;
    double diff = abs(v[i].first - v[j].first);
    return ((distance <= sum) and (distance >= diff));
}

int main(){

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n != -1) {

        vector< pair<float, pair<float, float> > > v(n);
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> v[i].second.first >> v[i].second.second >> v[i].first;
        }

        vector<int> p(n);
        for (int i = 0; i < n; ++i) p[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (p[i] != p[j] and intersect(v, i, j)) {
                    int old = max(p[i], p[j]);
                    int neu = min(p[i], p[j]);
                    for (int k = 0; k < n; ++k)
                        if (p[k] == old) p[k] = neu;
                }
            }
        }

        vector<int> c(n);
        int max = 0;
        for (int i = 0; i < n; ++i) {
            c[p[i]]++;
            if (c[p[i]] > max) max = c[p[i]];
        }

        cout << "The largest component contains " << max << " ring";
        cout << (max == 1 ? "":"s") << "." << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
