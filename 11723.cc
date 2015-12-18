#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MAX 10001

int main() {

    int cases = 0;

    string line;
    getline(cin, line);
    istringstream ss(line);

    int r, n;
    ss >> r >> n;

    while (r > 0 and n > 0 and r < MAX and n < MAX) {

        int d = (r-1) / n;

        cout << "Case " << ++cases << ": ";
        if (d <= 26) cout << d;
        else cout << "impossible";
        cout << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);

        ss >> r >> n;
    }
}
