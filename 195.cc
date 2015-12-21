#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

bool comp(char a, char b) {

	bool low_a = (a >= 'a');
	bool low_b = (b >= 'a');
	return (a - (low_a ? 'a':'A'))*2 + (low_a ? 1:0) <
            (b - (low_b ? 'a':'A'))*2 + (low_b ? 1:0);
}

int main() {

	string line;
	getline(cin, line);
	istringstream ss(line);

	int cases;
	ss >> cases;
	while (cases--) {

		getline(cin, line);
		ss.clear();
		ss.str(line);

		string s;
		ss >> s;

		sort(s.begin(), s.end(), comp);

		cout << s << endl;
		while (next_permutation(s.begin(), s.end(), comp)) cout << s << endl;
	}
}
