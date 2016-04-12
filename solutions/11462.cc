#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n) {
        
        getline(cin, line);
        ss.clear();
        ss.str(line);

        vector<int> ages(99);

        while (n--) {
            int age;
            ss >> age;
            ages[age-1]++;
        }

        bool first = true;
        for (int i = 0; i < 99; ++i) {
            while (ages[i]) {
                first ? first = false : cout << " ";
                cout << i+1;
                ages[i]--;
            }
        }
        cout << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
