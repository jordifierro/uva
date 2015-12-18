#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int cases = 0;
    ss >> cases;

    for (int i = 0; i < cases; ++i) {

       	getline(cin, line);
        ss.clear();
		ss.str(line);

		int n;
		ss >> n;

		vector<unsigned long long> v(10);
		for (int j = 1; j <= n; ++j) {
            int curr = j;
            while (curr) {
                ++v[curr%10];
                curr /= 10;
            }
		}

		for (int j = 0; j < 10; ++j) {
		  if (j) cout << " ";
		  cout << v[j];
		}
		cout << endl;
	}
}
