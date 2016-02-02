#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        int n;
        ss >> n;

        int i = 1;
        int sum = 1;
        while (n >= sum + i) sum += i++;

        cout << "TERM " << n << " IS ";
        int a = i - (n - sum);
        int b = n - sum + 1;
        cout << (0x01 & i ? a:b) << "/" << (0x01 & i ? b:a) << endl;
    }
}
