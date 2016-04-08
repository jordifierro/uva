#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

string notes[12] = {"C", "C#", "D", "D#", "E", "F",
                    "F#", "G", "G#", "A", "A#", "B"};

int main() {

    //for each note, save the scales that it vetoes
    map<string, int> hash;
    vector< vector<int> > vetoed(12);
    for (int i = 0; i < 12; ++i) {
        hash[notes[i]] = i;
        vetoed[(i+1)%12].push_back(i);
        vetoed[(i+3)%12].push_back(i);
        vetoed[(i+6)%12].push_back(i);
        vetoed[(i+8)%12].push_back(i);
        vetoed[(i+10)%12].push_back(i);
    }

    bool stop = false;
    while (!stop) {
        vector<bool> scale(12, true);

        string line;
        getline(cin, line);
        istringstream ss(line);

        //on every new note, mark the scales that become impossible
        string s;
        while (!stop and ss >> s) {
            if (s == "END") stop = true;
            else for (int i = 0; i < vetoed[hash[s]].size(); ++i)
                    scale[vetoed[hash[s]][i]] = false;
        }

        if (!stop) {
            bool first = true;
            for (int i = 0; i < 12; ++i) {
                if (scale[i]) {
                    first ? first = false : cout << " ";
                    cout << notes[i];
                }
            }
            cout << endl;
        }
    }
}
