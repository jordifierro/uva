#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void clean(vector< vector<int> > &table, vector<int> &hash, int until){

    int pos = hash[until];
    bool found = false;
    for (int i = table[pos].size() - 1; i > -1 and !found; --i) {
        if (table[pos][i] == until) found = true;
        else {
            int elem = table[pos][i];
            table[pos].pop_back();
            table[elem].push_back(elem);
            hash[elem] = elem;
        }
    }
}

void move(vector< vector<int> > &table, vector<int> &hash, int from, int to) {

    int pos_a = hash[from];
    int pos_b = hash[to];

    bool start = false;
    int amount = 0;
    for (int i = 0; i < table[pos_a].size(); ++i) {

        if (table[pos_a][i] == from) start = true;
        if (start) {
            int elem = table[pos_a][i];
            table[pos_b].push_back(elem);
            hash[elem] = pos_b;
            ++amount;
        }
    }

    for (int i = 0; i < amount; ++i) table[pos_a].pop_back();
}

void paint(const vector< vector<int> > &table) {

    for (int i = 0; i < table.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < table[i].size(); ++j)
            cout << " " << table[i][j];
        cout << endl;
    }
}


int main() {

    int n;
    cin >> n;
    cin.ignore();

    vector< vector<int> > table(n);
    for (int i = 0; i < n; ++i) table[i].push_back(i);

    vector<int> hash(n);
    for (int i = 0; i < n; ++i) hash[i] = i;

    string line;
    getline(cin, line);
    istringstream ss(line);

    string command;
    ss >> command;
    while (command != "quit") {

        string place;
        int from, to;
        ss >> from >> place >> to;
        if (from != to and hash[from] != hash[to]) {

            if (place == "onto") clean(table, hash, to);
            if (command == "move") clean(table, hash, from);
            move(table, hash, from, to);
        }

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> command;
    }

    paint(table);
}
