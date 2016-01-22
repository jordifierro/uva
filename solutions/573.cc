#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

	string line;
    getline(cin, line);
    istringstream ss(line);

    int height, day, night, fatigue;
    ss >> height;
    while (height) {
    	ss >> day >> night >> fatigue;

    	int day_fatigue = fatigue * day;

    	height *= 100;
    	day *= 100;
    	night *= 100;
    	fatigue *= 100;

    	int current = 0;
    	int number_days = 0;
    	bool bottom = false;

    	while (current <= height && !bottom) {
    		number_days++;
    		if (day > 0) current += day;
    		if (current <= height) {
    			current -= night;
    			day -= day_fatigue;
    		}
    		if (current < 0) bottom = true;
    	}

    	if(bottom) cout << "failure on day ";
    	else cout << "success on day ";
    	cout << number_days << endl;

    	getline(cin, line);
    	ss.clear();
        ss.str(line);
    	ss >> height;
    }
}
