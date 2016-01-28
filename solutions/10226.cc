#include <iostream>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);
    getline(cin, line);

    int n;
    ss >> n;
    while (n--) {

        int total = 0;
        map<string, int> trees;

        bool stop = false;
        while (!stop) {

            if (!getline(cin, line)) stop = true;
            else {
                ss.clear();
                ss.str(line);
                string tree;
                if (line != "") {
                    trees[line]++;
                    total++;
                }
                else stop = true;
            }
        }

        map<string, int>::iterator it;
        for (it = trees.begin(); it != trees.end(); it++) {
            cout << it->first << " " << fixed << setprecision(4);
            cout << (double)it->second / (double)total * 100 << endl;
        }
        if (n) cout << endl;
    }
}
