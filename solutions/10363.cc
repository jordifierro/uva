#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n--) {

        vector< vector<char> > v(3, vector<char> (3));

        for (int i = 0; i < 3; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> v[i][0] >> v[i][1] >> v[i][2];
        }

        int nx = 0;
        int no = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (v[i][j] == 'X') nx++;
                else if (v[i][j] == 'O') no++;
            }
        }

        int hor_x_lines, ver_x_lines, dia_x_lines;
        int hor_o_lines, ver_o_lines, dia_o_lines;
        hor_x_lines = ver_x_lines = dia_x_lines = 0;
        hor_o_lines = ver_o_lines = dia_o_lines = 0;

        for (int i = 0; i < 3; ++i) {
            if (v[i][0] == 'X' and v[i][1] == 'X' and v[i][2] == 'X')
                hor_x_lines++;
            if (v[i][0] == 'O' and v[i][1] == 'O' and v[i][2] == 'O')
                hor_o_lines++;
            if (v[0][i] == 'X' and v[1][i] == 'X' and v[2][i] == 'X')
                ver_x_lines++;
            if (v[0][i] == 'O' and v[1][i] == 'O' and v[2][i] == 'O')
                ver_o_lines++;
        }
        if (v[0][0] == 'X' and v[1][1] == 'X' and v[2][2] == 'X') dia_x_lines++;
        if (v[0][0] == 'O' and v[1][1] == 'O' and v[2][2] == 'O') dia_o_lines++;
        if (v[2][0] == 'X' and v[1][1] == 'X' and v[0][2] == 'X') dia_x_lines++;
        if (v[2][0] == 'O' and v[1][1] == 'O' and v[0][2] == 'O') dia_o_lines++;

        bool correct = true;
        if (   !(nx == no or nx == no+1)
            or (hor_x_lines > 1 or hor_o_lines > 1 or
                ver_o_lines > 1 or ver_o_lines > 1)
            or (hor_x_lines + ver_x_lines + dia_x_lines >= 1 and
                hor_o_lines + ver_o_lines + dia_o_lines >= 1)
            or (hor_x_lines + ver_x_lines + dia_x_lines >= 1 and no == nx)
            or (hor_o_lines + ver_o_lines + dia_o_lines >= 1 and nx == no+1)
           ) cout << "no" << endl;
        else cout << "yes" << endl;

        getline(cin, line);
    }
}
