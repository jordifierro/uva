#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define GRANT 40

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n, k;
    ss >> n >> k;
    while (n and k) {

        vector<int> students(n);
        int satified = 0;
        int i_stu = 0;
        int i_mo = 0;
        int money = i_mo+1;

        while (satified < n) {

            if (students[i_stu] != GRANT) {
                if (students[i_stu] + money >= GRANT) {
                    money -= GRANT - students[i_stu];
                    students[i_stu] = GRANT;
                    cout << (i_stu+1 > 9? " ":"  ") << i_stu+1;
                    ++satified;
                } else {
                    students[i_stu] += money;
                    money = 0;
                }
            }

            if (money == 0) {
                i_mo = (i_mo+1)%k;
                money = i_mo + 1;
            }
            i_stu = (i_stu+1) % n;
        }
        cout << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n >> k;
    }
}
