#include <iostream>
#include <vector>

using namespace std;

int main() {

    int c[5] = {1, 5, 10, 25, 50};

    vector<unsigned long long> v(310000);
    v[0] = 1;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j <= 300000; ++j)
            if (v[j]) v[ j+c[i] ] += v[j];

    int n;
    while (cin >> n) {
        if (v[n] == 1) cout << "There is only 1 way";
        else cout << "There are " << v[n] << " ways";
        cout << " to produce " << n << " cents change." << endl;
    }
}
