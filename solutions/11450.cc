#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int c;
    ss >> c;
    for (int l = 0; l < c; ++l) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int budget, garments;
        ss >> budget >> garments;

        vector<int> valid_garm(budget + 1, -1);
        vector<bool> poss_budg(budget + 1, false);
        valid_garm[0] = 0;

        for (int i = 0; i < garments; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            int number, price;
            ss >> number;
            for (int r = 0; r < number; ++r) {

                ss >> price;
                for (int j = 0; j < valid_garm.size(); ++j)
                    if (valid_garm[j] == i and j+price < valid_garm.size())
                        poss_budg[j+price] = true;
            }

            for (int j = 0; j < valid_garm.size(); ++j) {
                if (poss_budg[j]) valid_garm[j] = i+1;
                poss_budg[j] = false;
            }
        }

        bool solution = false;
        for (int i = valid_garm.size()-1; i > 0 and !solution; --i) {
            if (valid_garm[i] == garments) {
                solution = true;
                cout << i << endl;
            }
        }
        if (!solution) cout << "no solution" << endl;
    }
}
