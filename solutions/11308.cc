#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

void getline_into(istringstream& ss) {

    string line;
    getline(cin, line);
    ss.clear();
    ss.str(line);
}

int main() {

    istringstream ss;

    getline_into(ss);
    int t;
    ss >> t;
    while (t--) {

        string title;
        getline(cin, title);

        getline_into(ss);
        int m, n, b;
        ss >> m >> n >> b;

        map<string, int> ingredients;
        for (int i = 0; i < m; ++i) {
            getline_into(ss);
            string ing;
            int pri;
            ss >> ing >> pri;

            ingredients[ing] = pri;
        }

        vector< pair<int, string> > result;

        for (int i = 0; i < n; ++i) {

            string recipe;
            getline(cin, recipe);

            getline_into(ss);
            int c;
            ss >> c;

            int total = 0;
            for (int j = 0; j < c; ++j) {
                getline_into(ss);
                string ing;
                int amount;
                ss >> ing >> amount;

                total += ingredients[ing] * amount;
            }

            if (total <= b) result.push_back(make_pair(total, recipe));
        }

        sort(result.begin(), result.end());
        transform(title.begin(), title.end(), title.begin(), ::toupper);

        cout << title << endl;
        if (result.size())
            for (int i = 0; i < result.size(); ++i)
                cout << result[i].second << endl;
        else cout << "Too expensive!" << endl;
        cout << endl;
    }
}
