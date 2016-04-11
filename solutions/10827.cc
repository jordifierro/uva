#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int cases;
    ss >> cases;
    while (cases--) {

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int n;
        ss >> n;
        vector< vector<int> > matrix(2*n, vector<int> (n));

        for (int i = 0; i < n; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            for (int j = 0; j < n; ++j) {
                ss >> matrix[i][j];
                matrix[i+n][j] = matrix[i][j];
            }
        }

        for (int j = 0; j < n; ++j)
            for (int i = 1; i < 2*n; ++i)
                matrix[i][j] += matrix[i-1][j];

        int max_seq = 0;
        for (int i = 1; i < 2*n; ++i) {
            for (int j = i; j < 2*n and j-i < n; ++j) {

                /*  The best subarray from rows i to j will be the max kadane's
                    algorithm sum or total columns sum minus the best negative
                    subsequence, also calculated using kadane's algorithm     */
                    
                int total_sum = 0;
                for (int k = 0; k < n; ++k)
                    total_sum += matrix[j][k] - matrix[i-1][k];

                int sum_max, sum_min, best_max, best_min;
                sum_max = sum_min = best_max = best_min = 0;
                for (int k = 0; k < n; ++k) {

                    sum_max += matrix[j][k] - matrix[i-1][k];
                    sum_min += matrix[j][k] - matrix[i-1][k];

                    best_max = max(best_max, sum_max);
                    sum_max = max(sum_max, 0);
                    best_min = min(best_min, sum_min);
                    sum_min = min(sum_min, 0);
                }

                max_seq = max(max_seq, max(best_max, total_sum - best_min));
            }
        }

        cout << max_seq << endl;
    }
}
