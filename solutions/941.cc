#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    vector<unsigned long long int> v(20);
    v[0] = 1;
    for (int i = 1; i < 20; ++i) v[i] = v[i-1] * (i+1);

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n--) {
        
        getline(cin, line);
        ss.clear();
        ss.str(line);
        string s;
        ss >> s;
        sort(s.begin(), s.end());

        getline(cin, line);
        ss.clear();
        ss.str(line);
        unsigned long long int p;
        ss >> p;

        for (int i = s.size()-1; i > 0; --i) {
            int a = p / v[i-1];
            p %= v[i-1];
            cout << s[a];
            s.erase(a, 1);
        }
        cout << s[0] << endl;
    }
}
