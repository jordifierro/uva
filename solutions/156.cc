#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_anagram(string a, string b) {

    if (a.size() != b.size()) return false;

    vector<int> va(26), vb(26);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] >= 'a') ++va[a[i] - 'a'];
        else ++va[a[i] - 'A'];
        if (b[i] >= 'a') ++vb[b[i] - 'a'];
        else ++vb[b[i] - 'A'];
    }

    for (int i = 0; i < 26; ++i)
        if(va[i] != vb[i]) return false;

    return true;
}

int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    vector<string> dict;
    string word;
    ss >> word;
    while (word != "#") {

        dict.push_back(word);
        while (ss >> word) dict.push_back(word);

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> word;
    }

    vector<bool> is_ana(dict.size());
    for (int i = 0; i < dict.size(); ++i) {
        if (dict[i].size() > 1) {
            for (int j = 0; j < dict.size() and !is_ana[i]; ++j) {
                if (i != j and is_anagram(dict[i], dict[j])) {
                    is_ana[i] = true;
                    is_ana[j] = true;
                }
            }
        }
    }

    vector<string> ananas;
    for (int i = 0; i < dict.size(); ++i)
        if (!is_ana[i]) ananas.push_back(dict[i]);

    sort(ananas.begin(), ananas.end());

    for (int i = 0; i < ananas.size(); ++i)
        cout << ananas[i] << endl;

}
