#include <iostream>
#include <vector>

using namespace std;

#define GOAL 1500

int main() {

    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    vector<int> ugly(1);
    ugly[0] = 1;
    for (int i = 1; i < GOAL; ++i) {
        while(ugly[i2] * 2 <= ugly[ugly.size()-1]) ++i2;
        while(ugly[i3] * 3 <= ugly[ugly.size()-1]) ++i3;
        while(ugly[i5] * 5 <= ugly[ugly.size()-1]) ++i5;

        if (ugly[i2] * 2 < ugly[i3] * 3 and ugly[i2] * 2 < ugly[i5] * 5) {
            ugly.push_back(ugly[i2++] * 2);
        } else if (ugly[i3] * 3 < ugly[i5] * 5) {
            ugly.push_back(ugly[i3++] * 3);
        } else ugly.push_back(ugly[i5++] *+ 5);
    }
    cout << "The 1500'th ugly number is " << ugly[ugly.size()-1] << "." << endl;
}
