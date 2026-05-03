#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

class Graf {
private:
    map<string, vector<pair<string, int>>> adj;

public:
    void tambah_edge(string u, string v, int jarak) {
        adj[u].push_back({v, jarak});
        adj[v].push_back({u, jarak}); // tidak berarah
    }

    // BFS (rute terpendek berdasarkan jumlah simpul)
    void bfs(string start, string tujuan) {
        queue<vector<string>> q;
        set<string> visited;

        q.push({start});
        visited.insert(start);

        while (!q.empty()) {
            vector<string> path = q.front();
            q.pop();

            string node = path.back();

            if (node == tujuan) {
                cout << "Rute BFS: ";
                for (string s : path) cout << s << " -> ";
                cout << "SELESAI\n";
                return;
            }

            for (auto tetangga : adj[node]) {
                if (!visited.count(tetangga.first)) {
                    visited.insert(tetangga.first);
                    vector<string> new_path = path;
                    new_path.push_back(tetangga.first);
                    q.push(new_path);
                }
            }
        }
    }

    // DFS (rekursif)
    void dfs_util(string node, string tujuan, set<string>& visited, vector<string>& path, bool& found) {
        visited.insert(node);
        path.push_back(node);

        if (node == tujuan) {
            cout << "Rute DFS: ";
            for (string s : path) cout << s << " -> ";
            cout << "SELESAI\n";
            found = true;
            return;
        }

        for (auto tetangga : adj[node]) {
            if (!visited.count(tetangga.first) && !found) {
                dfs_util(tetangga.first, tujuan, visited, path, found);
            }
        }

        path.pop_back(); // backtrack
    }

    void dfs(string start, string tujuan) {
        set<string> visited;
        vector<string> path;
        bool found = false;
        dfs_util(start, tujuan, visited, path, found);
    }
};

int main() {
    Graf g;

    // Contoh jaringan masjid (dummy)
    g.tambah_edge("Masjid_A", "Masjid_B", 2);
    g.tambah_edge("Masjid_A", "Masjid_C", 4);
    g.tambah_edge("Masjid_B", "Masjid_D", 3);
    g.tambah_edge("Masjid_C", "Masjid_D", 1);
    g.tambah_edge("Masjid_D", "Masjid_E", 2);
    g.tambah_edge("Masjid_A", "Masjid_E", 10);
    

    string start = "Masjid_A";
    string tujuan = "Masjid_E";

    cout << "Dari " << start << " ke " << tujuan << endl;

    g.bfs(start, tujuan);
    g.dfs(start, tujuan);

    return 0;
}