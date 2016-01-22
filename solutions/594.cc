#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MAX 2147483648

int main() {

    string line;
    while (getline(cin, line)) {
    	istringstream ss(line);

    	long n;
    	ss >> n;

    	vector<bool> computer(32);
    	long copy = n;
    	for (int i = 0; i < 32; ++i) {
    		if (copy & 0x01) computer[i] = true;
    		copy >>= 1;
    	}

    	long m = 0;
    	for (int i = 7; i >= 0; --i) {
    		m <<= 1;
    		m = m | (computer[i]?0x01:0);
    	}
    	for (int i = 15; i >= 8; --i) {
    		m <<= 1;
    		m = m | (computer[i]?0x01:0);
    	}
    	for (int i = 23; i >= 16; --i) {
    		m <<= 1;
    		m = m | (computer[i]?0x01:0);
    	}
    	for (int i = 31; i >= 24; --i) {
    		m <<= 1;
    		m = m | (computer[i]?0x01:0);
    	}

    	if (m >= MAX) m -= MAX*2;

    	cout << n << " converts to " << m << endl;
    }
}
