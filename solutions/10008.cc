#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>

using namespace std;

bool my_comp (pair<int,int> a, pair<int,int> b) {

    if (a.first < b.first) return false;
    if (a.first > b.first) return true;
    return a.second < b.second;
}

int main() {

    vector< pair<int, int> > v(26);
    for (int i = 0; i < 26; ++i) v[i].second = i;

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream ss(line);

        char a;
        while (ss >> a) {
            if (a >= 'a' and a <= 'z') v[a-'a'].first++;
            else if (a >= 'A' and a <= 'Z') v[a-'A'].first++;
        }
    }

    sort(v.begin(), v.end(), my_comp);
    for (int i = 0; i < 26 and v[i].first; ++i)
        cout << (char)(v[i].second + 'A') << " " << v[i].first << endl;
}
