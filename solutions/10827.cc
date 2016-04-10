#include <iostream>
#include <vector>
#include <sstream>

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
        vector< vector<int> > matrix(2*n, vector<int> (2*n));

        for (int i = 0; i < n; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);

            for (int j = 0; j < n; ++j) {
                int a;
                ss >> a;
                matrix[i][j] = matrix[i+n][j] =
                    matrix[i][j+n] = matrix[i+n][j+n] = a;
            }
        }

        //precalculate the cumulated sum of the columns
        for (int j = 0; j < 2*n; ++j)
            for (int i = 0; i < 2*n; ++i)
                if (i) matrix[i][j] += matrix[i-1][j];

        //for each quartet row(k to i) and column(y to j) calculate the sum
        int max = 0;
        for (int i = 0; i < 2*n; ++i) {
            for (int k = (i-n+1 >= 0 ? i-n+1 : 0); k <= i; ++k) {

                for (int j = 0; j < 2*n; ++j) {
                    int sum = 0;
                    for (int y = (j-n+1 >= 0 ? j-n+1 : 0); y <= j; ++y) {

                        if (sum < 0) sum = 0;
                        //add the sum of the column y from k to i
                        sum += (matrix[i][y] - (k ? matrix[k-1][y] : 0));
                        if (sum > max) max = sum;
                    }
                }
            }
        }

        cout << max << endl;
    }
}
