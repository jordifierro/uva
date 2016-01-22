#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

#define MAX 200
#define err 0.00001

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int ini_height, workers;
    ss >> ini_height >> workers;
    while (ini_height or workers) {

        // (workers/ini_height) = (n/n+1)^(l-1)
        int levels = 2;
        bool found = false;
        while (levels < MAX and !found) {
            double p = pow(workers, 1.0/(levels-1));
            double q = pow(ini_height, 1.0/(levels-1));
            if (abs(q - (p + 1)) < err) found = true;
            else ++levels;
        }
        if (workers == 1) levels = log2(ini_height) + 1;

        double childs = pow(workers, 1.0/(levels-1));
        double no_workers = (1 - pow(childs, levels-1)) / (1-childs);
        double total_heights = (1 - pow(childs/(childs+1), levels))
                                / (1 - childs/(childs+1))
                                * ini_height;
        if (childs == 1) no_workers = log2(ini_height);

        cout << (int)(no_workers + err) << " " << (int)(total_heights + err) << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> ini_height >> workers;
    }
}
