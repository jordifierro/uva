#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int count_moves(vector<int> &v, int left, int right) {

    if (right-left == 0) return 0;

    int left_moves = count_moves(v, left, (left + right)/2);
    int right_moves = count_moves(v, (left + right)/2 + 1, right);
    int moves = left_moves + right_moves;

    vector<int> aux(right - left + 1);
    int li = left;
    int middle = (left + right)/2 + 1;
    int ri = middle;

    int i = 0;
    for(; i < right - left + 1  and li < middle and ri <= right; ++i){
        if (v[li] < v[ri]) {
            aux[i] = v[li];
            li++;
        } else {
            aux[i] = v[ri];
            ri++;
            moves += middle - li;
        }
    }

    while (li < middle) {
        aux[i] = v[li];
        ++i;
        ++li;
    }
    while (ri <= right) {
        aux[i] = v[ri];
        ++i;
        ++ri;
    }
    for (int j = 0; j < aux.size(); ++j) v[left + j] = aux[j];

    return moves;
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n) {

        vector<int> v(n);
        for(int i = 0; i < n; ++i) ss >> v[i];

        if (count_moves(v, 0, v.size()-1) & 0x01)
            cout << "Marcelo" << endl;
        else cout << "Carlos" << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
