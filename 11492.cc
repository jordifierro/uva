#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

int dijkstra(   vector< vector< pair<int, pair<string, bool> > > > &g,
                int start_lang, int end_lang) {

    //priority_queue composed by <<total_lenght, last_letter>, language>
    priority_queue< pair< pair<int, char>, int > > pq;
    pq.push(make_pair(make_pair(0, 'A'), start_lang));

    while (!pq.empty()) {

        pair< pair<int, char>, int > p = pq.top();
        pq.pop();

        if (p.second == end_lang) return -p.first.first;

        for (int i = 0; i < g[p.second].size(); ++i) {

            //if !used(current_edge) and
            // first_letter(current_edge) != last_letter
            if (   !g[p.second][i].second.second and
                    g[p.second][i].second.first[0] != p.first.second) {

                //add this edge to the queue
                //inverse length to let the queue sort the shortest first
                pq.push(
                    make_pair(
                        make_pair(  -(-(p.first.first) +
                        g[p.second][i].second.first.size()),
                        g[p.second][i].second.first[0]),
                        g[p.second][i].first));

                //mark the edge as used
                g[p.second][i].second.second = true;
            }
        }
    }

    return -1;
}


int main() {

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n) {

        //map to get the corresponding index for each language
        map<string, int> m;
        //graph: vector of connections <language , <word, used>>
        vector< vector< pair<int, pair<string, bool> > > > graph;
        int graph_index = 0;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        string start_lang, end_lang;
        ss >> start_lang >> end_lang;

        for (int i = 0; i < n; ++i) {

            getline(cin, line);
            ss.clear();
            ss.str(line);
            string a, b, w;
            ss >> a >> b >> w;

            if (m.find(a) == m.end()){
                m[a] = graph_index;
                graph_index++;
                graph.push_back(vector< pair<int, pair<string, bool> > > ());
            }
            if (m.find(b) == m.end()){
                m[b] = graph_index;
                graph_index++;
                graph.push_back(vector< pair<int, pair<string, bool> > > ());
            }

            graph[m[a]].push_back(make_pair(m[b], make_pair(w,false)));
            graph[m[b]].push_back(make_pair(m[a], make_pair(w,false)));
        }

        if (m.find(start_lang) == m.end() or m.find(end_lang) == m.end()) {
            cout << "impossivel" << endl;
        } else {
            int cost = dijkstra(graph, m[start_lang], m[end_lang]);
            if(cost < 0) cout << "impossivel" << endl;
            else cout << cost << endl;
        }

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}
