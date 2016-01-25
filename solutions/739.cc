#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string encode(char a) {

    if (a == 'B' or a == 'P' or a == 'F' or a == 'V') return "1";
    if (a == 'C' or a == 'S' or a == 'K' or a == 'G') return "2";
    if (a == 'J' or a == 'Q' or a == 'X' or a == 'Z') return "2";
    if (a == 'D' or a == 'T') return "3";
    if (a == 'L') return "4";
    if (a == 'M' or a == 'N') return "5";
    if (a == 'R') return "6";
    return "0";
}

int main() {

    vector<string> v;

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        string s;
        ss >> s;
        if (s != "") v.push_back(s);
    }

    cout << "         NAME                     SOUNDEX CODE" << endl;

    for (int i = 0; i < v.size(); ++i) {
        cout << "         " << v[i];
        for (int j = v[i].size(); j < 25; ++j) cout << " ";
        cout << v[i][0];

        int encoded = 0;
        for (int j = 1; j < v[i].size() and encoded < 3; ++j) {
            string e = encode(v[i][j]);
            if (e != "0" and e != encode(v[i][j-1])) {
                cout << e;
                encoded++;
            }
        }
        
        while (encoded < 3) {
            cout << "0";
            encoded++;
        }
        cout << endl;
    }
    cout << "                   END OF OUTPUT" << endl;
}
