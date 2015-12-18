#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	int cases;
	cin >> cases;

	for (int i = 1; i <= cases; ++i) {

		double d, v, u;
		cin >> d >> v >> u;

		if (v >= u || v == 0 || u == 0) {
            cout << "Case " << i << ": " << "can't determine"<< endl;
        } else {
            /*
                  /|
               u / |v
                /__|
                 x
            */
            double x = sqrt(u*u - v*v);
            double shortest = d/x;
            double fastest = d/u;

            cout << "Case " << i << ": ";
            cout << fixed << setprecision(3) << shortest - fastest << endl;
		}
	}
}
