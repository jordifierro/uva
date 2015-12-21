#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

#define DECK_SIZE 52

bool compatible(const string &a, const string &b) {

	if(a[0] == b[0]) return true;
	if(a[1] == b[1]) return true;
	return false;
}


int main() {

	bool finish = false;
	while (!finish) {

		string line;
    	getline(cin, line);
    	istringstream ss(line);

    	string first_elem;
    	ss >> first_elem;
    	if (first_elem == "#") finish = true;
    	else {

    		vector< stack<string> > v(DECK_SIZE, stack<string> ());
    		v[0].push(first_elem);

            string temp;
    		for (int i = 1; i < DECK_SIZE/2; ++i) {
    			ss >> temp;
    			v[i].push(temp);
    		}

    		getline(cin, line);
    		ss.clear();
    		ss.str(line);

			for (int i = DECK_SIZE/2; i < DECK_SIZE; ++i) {
    			ss >> temp;
    			v[i].push(temp);
    		}

    		int total = v.size();
    		for (int i = 0; i < total; ++i) {

    			string curr = v[i].top();
    			if (i > 2 and compatible(curr, v[i-3].top())) {

					v[i].pop();
    				v[i-3].push(curr);
    				if (v[i].empty()) {
    					v.erase(v.begin() + i);
    					total--;
    				}
    				i -= 4;

    			} else if (i and compatible(curr, v[i-1].top())) {

					v[i].pop();
    				v[i-1].push(curr);
    				if (v[i].empty()) {
    					v.erase(v.begin() + i);
    					total--;
    				}
    				i -= 2;
    			}
    		}

    		int final = v.size();
    		cout << final << " pile";
            cout << (v.size() != 1 ? "s":"") << " remaining:";
    		for (int i = 0; i < final; ++i) cout << " " << v[i].size();
    		cout << endl;
    	}
	}
}
