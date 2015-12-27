#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct carray {
	string name;
	int base, element_size, dimens;
	vector<int> lower, upper;
    vector<unsigned long long int> acum;
};


int main() {

	string line;
    getline(cin, line);
    istringstream ss(line);


    int n, r;
    ss >> n >> r;

    map<string, carray> hash;

    for (int i = 0; i < n; ++i) {

    	getline(cin, line);
    	ss.clear();
    	ss.str(line);

        carray a;
    	ss >> a.name >> a.base >> a.element_size >> a.dimens;
    	unsigned long long prev = a.element_size;
    	for (int j = 0; j < a.dimens; ++j) {
    		int lo, up;
    		ss >> lo >> up;
    		a.lower.push_back(lo);
    		a.upper.push_back(up);
    	}

        a.acum = vector<unsigned long long int> (a.dimens);
        a.acum[a.dimens - 1] = a.element_size;
        for (int j = a.dimens - 2; j >= 0; --j)
            a.acum[j] = a.acum[j+1]*(a.upper[j+1]-a.lower[j+1]+1);

    	hash[a.name] = a;
    }

    for (int i = 0; i < r; ++i) {

    	getline(cin, line);
    	ss.clear();
    	ss.str(line);

    	string name;
    	ss >> name;

    	carray sel = hash[name];
    	int number = sel.dimens;

    	unsigned long long address = sel.base;

    	vector<int> v(number);

    	for (int j = 0; j < number; ++j) {
    		ss >> v[j];
    		address += (v[j] - sel.lower[j]) * sel.acum[j];
    	}
    	cout << name << "[";
    	for (int j = 0; j < number; ++j) {
    		if(j) cout << ", ";
    		cout << v[j];
    	}
    	cout << "] = " << address << endl;
    }
}
