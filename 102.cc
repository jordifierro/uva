#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define BIN 3

string binify(int perm) {
    string perms[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    return perms[perm];
}

long sum(const vector<int> &bins, int b, int g, int c){
    return bins[b] + bins[g + BIN] + bins[c + BIN*2];
}

int main() {

    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        vector<int> bins(BIN * 3);
        long total_bottles = 0;
        for (int i = 0; i < BIN * 3; ++i) {
            ss >> bins[i];
            total_bottles += bins[i];
        }

        vector<long> remain(6);
        remain[1] = sum(bins, 0, 1, 2); // BGC
        remain[0] = sum(bins, 0, 2, 1); // BCG
        remain[4] = sum(bins, 1, 0, 2); // GBC
        remain[5] = sum(bins, 1, 2, 0); // GCB
        remain[2] = sum(bins, 2, 0, 1); // CBG
        remain[3] = sum(bins, 2, 1, 0); // CGB

        int max_perm = 0;
        for (int i = 1; i < 6; ++i) {
            if (remain[i] > remain[max_perm]) max_perm = i;
        }

        cout << binify(max_perm) << " ";
        cout << total_bottles - remain[max_perm] << endl;
    }
}
