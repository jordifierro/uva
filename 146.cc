#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

	string line;
    getline(cin, line);
    istringstream ss(line);

    string s;
    ss >> s;

    while (s != "#") {

    	if(next_permutation(s.begin(), s.end())) cout << s << endl;
		else cout << "No Successor" << endl;

    	getline(cin, line);
    	ss.clear();
    	ss.str(line);
    	ss >> s;
    }
}
