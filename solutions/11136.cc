#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n) {

        map<int, int> bills;
        unsigned long long total = 0;

        for (int i = 0; i < n; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            int c;
            ss >> c;
            for (int j = 0; j < c; ++j) {
                int b;
                ss >> b;
                bills[b]++;
            }

            map<int, int>::iterator beg = bills.begin();
            map<int, int>::reverse_iterator en = bills.rbegin();

            total += en->first - beg->first;
            beg->second--;
            en->second--;

            //if en and beg elements has reached 0 value erase them
            if (en->first != beg->first) {
                if (!beg->second) bills.erase(beg);
                if (!en->second) bills.erase(--en.base());
            }
            else if (!beg->second) bills.erase(beg);
        }

        cout << total << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
