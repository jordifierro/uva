#include <iostream>
#include <sstream>

using namespace std;

int main() {

    bool even = true;

    string line;
    while (getline(cin, line)) {

        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '"') {
                if (even) cout << "``";
                else cout << "''";
                even = !even;
            } else cout << line[i];
        }
        cout << endl;
    }
}
