#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

	string line;
    getline(cin, line);
    istringstream ss(line);

    int p;
    ss >> p;
    while (p--) {

    	getline(cin, line);
    	ss.clear();
    	ss.str(line);

    	int n;
    	ss >> n;
    	vector<int> v(n);

    	getline(cin, line);
    	ss.clear();
    	ss.str(line);

        int total = 0;
    	for (int i = 0; i < n; ++i) {
    		ss >> v[i];
    		total += v[i];
    	}

    	vector<bool> dp(total + 1);
    	dp[0] = true;
        
    	for (int i = 0; i < n; ++i)
    		for (int j = total - v[i]; j >= 0; --j)
    			if (dp[j]) dp[j + v[i]] = true;

    	int i;
    	for (i = total/2; i <= total; ++i) if (dp[i]) break;

    	cout << abs(2*i - total) << endl;
    }
}
