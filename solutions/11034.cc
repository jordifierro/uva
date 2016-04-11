#include <iostream>
#include <sstream>
#include <queue>

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

        int l, m;
        ss >> l >> m;
        l *= 100;

        queue<int> left;
        queue<int> right;
        for (int i = 0; i < m; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            int a;
            string side;
            ss >> a >> side;

            if (side == "left") left.push(a);
            else right.push(a);
        }

        int travels = 0;
        bool left_side = true;
        while (!left.empty() or !right.empty()) {

            int charge = 0;
            queue<int> current = (left_side ? left : right);
            while (!current.empty() and charge + current.front() <= l) {
                charge += current.front();
                current.pop();
            }
            left_side ? left = current : right = current;

            ++travels;
            left_side = !left_side;
        }

        cout << travels << endl;
    }
}
