#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int convert(string time) {

    return  time[7]-'0' + (time[6]-'0') * 10 +
            (time[4]-'0' + (time[3]-'0') * 10) * 60 +
            (time[1]-'0' + (time[0]-'0') * 10) * 3600;
}

int main() {

    unsigned long long int dist = 0;
    double last_vel = 0;
    double last_time = 0;

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        string time;
        int vel;
        ss >> time;
        int current = convert(time);

        if (ss >> vel) {
            dist += last_vel * (current - last_time) / 3.6;
            last_vel = vel;
            last_time = current;
        }
        else {
            cout << time << " " << fixed << setprecision(2);
            cout << (dist + (current-last_time) * last_vel / 3.6) / 1000;
            cout << " km" << endl;
        }
    }
}
