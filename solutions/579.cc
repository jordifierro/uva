#include <iostream>
#include <sstream>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

pair<int, int> get_time() {

    string line;
    getline(cin, line);
    stringstream ss(line);
    string s;
    ss >> s;

    int h = s[0]-'0';
    int m = (s[2]-'0')*10 + (s[3]-'0');
    if (s[1] != ':') {
        h = h*10 + (s[1] - '0');
        m = (s[3] - '0')*10 + (s[4] - '0');
    }
    return make_pair(h, m);
}

int main() {

    pair<int, int> t = get_time();
    while (t.first or t.second) {

        double dh = (double)t.first*(360./12.) + (double)t.second/2.;
        if (dh >= 360.) dh -= 360.;
        double dm = (double)t.second*(double)(360./60.);

        double diff = max(dh,dm) - min(dh,dm);
        if (diff >= 180) diff = 360 - diff;

        cout << fixed << setprecision(3) << diff << endl;

        t = get_time();
    }
}
