#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    while (n > -1) {

        bool found = false;
        int people = 0;

        for (int i = sqrt(n) + 1; i > 0 && !found; --i) {
            
            people = i;
            int cocos = n;
            bool stop = false;
            for (int j = 0; j < people && !stop; ++j) {
                if ( !(cocos%people == 1) ) stop = true;
                cocos -= (cocos/people + 1);
            }
            if (!stop && cocos % people == 0) found = true;
        }

        cout << n << " coconuts, ";
        if (found) cout << people << " people and 1 monkey" << endl;
        else cout << "no solution" << endl;

        cin >> n;
    }
}
