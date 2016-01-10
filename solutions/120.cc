#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int find_pos(const vector<int> &v, int begin, int end, int elem) {
    for (int i = begin; i <= end; ++i) if(v[i] == elem) return i;
    return -1;
}

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        vector<int> sorted, stack, flips;
        int diameter;
        while (ss >> diameter) {
            cout << (sorted.size()?" ":"") << diameter;
            sorted.push_back(diameter);
            stack.push_back(diameter);
        }
        cout << endl;

        sort(sorted.begin(), sorted.end());

        for (int i = sorted.size() - 1; i > 0; --i) {

            int elem = sorted[i];
            if (stack[i] != elem && stack[0] != elem) {
                int pos = find_pos(stack, 0, i, elem);
                flips.push_back(sorted.size() - pos);
                reverse(stack.begin(), stack.begin() + pos + 1);
            }
            if (stack[0] == elem) {
                flips.push_back(sorted.size() - i);
                reverse(stack.begin(), stack.begin() + i + 1);
            }
        }
        flips.push_back(0);

        for (int i = 0; i < flips.size(); ++i)
            cout << (i?" ":"") << flips[i];
        cout << endl;
    }
}
