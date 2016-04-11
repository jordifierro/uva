#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

bool comp(const pair<int, string> &a, const pair<int, string> &b) {

    if (a.first > b.first) return true;
    if (b.first > a.first) return false;
    return a.second<b.second;
}

bool is_project(string s) {

    for(int i = 0; i < s.size(); ++i)
        if((s[i] < 'A' or s[i] > 'Z') and s[i] != ' ') return false;

    return true;
}


int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    while (line[0] != '0') {

        vector< pair<int, string> > v;
        map<string, int> projs;
        map<string, int> studs;
        int index = 0;

        while (line[0] != '1') {

            string project = line;
            v.push_back(make_pair(0, project));
            projs[project] = index;
            index++;

            getline(cin, line);
            ss.clear();
            ss.str(line);

            while (line[0] != '1' and !is_project(line)) {

                string std = line;
                if (studs.find(std) != studs.end()) {
                    if (studs[std] != projs[project] and studs[std] != -1) {
                        v[studs[std]].first--;
                        studs[std] = -1;
                    }
                }
                else {
                    studs[std] = projs[project];
                    v[studs[std]].first++;
                }

                getline(cin, line);
                ss.clear();
                ss.str(line);
            }
        }

        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < v.size(); ++i)
            cout << v[i].second << " " << v[i].first << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
    }
}
