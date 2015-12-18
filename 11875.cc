#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int cases;
    ss >> cases;

	for(int i = 0; i < cases; ++i) {

		getline(cin, line);
		ss.clear();
		ss.str(line);

		int n;
		ss >> n;
		vector<int> v(n);
		for(int j = 0; j < n; ++j) ss >> v[j];

		cout << "Case " << i + 1 << ": " << v[n / 2] << endl;
	}
}
