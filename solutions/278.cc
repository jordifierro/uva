#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        char command;
        int x, y;
        ss >> command >> x >> y;
        
        if (command == 'r' or command == 'Q') cout << min(x, y) << endl;
        else if (command == 'k') cout << ((x * y) + 1) / 2 << endl;
        else if (command == 'K') cout << ((x + 1) / 2) * ((y + 1) / 2)  << endl;
    }
}
