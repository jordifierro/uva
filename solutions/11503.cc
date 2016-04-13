#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

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

        int n;
        ss >> n;

        map<string, int> fr_hash;
        vector<int> group;
        int index = 0;

        for (int i = 0; i < n; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            string fa, fb;
            ss >> fa >> fb;

            if (fr_hash.find(fa) == fr_hash.end()) {
                fr_hash[fa] = index;
                group.push_back(index);
                index++;
            }
            if (fr_hash.find(fb) == fr_hash.end()){
                fr_hash[fb] = index;
                group.push_back(index);
                index++;
            }

            int neu = min(group[fr_hash[fa]], group[fr_hash[fb]]);
            int old = max(group[fr_hash[fa]], group[fr_hash[fb]]);

            int friends = 0;
            for (int i = 0; i < group.size(); ++i) {
                if (group[i] == old) group[i] = neu;
                if (group[i] == neu) ++friends;
            }

            cout << friends << endl;
        }
    }
}
