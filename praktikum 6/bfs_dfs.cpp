#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Graf {
private:
    map<int, vector<int>> adj;
    bool berarah;

public:
    Graf(bool berarah = false) { // 🔥 diubah jadi tidak berarah
        this->berarah = berarah;
    }

    void tambah_node(int node) {
        if (adj.find(node) == adj.end()) {
            adj[node] = {};
        }
    }

    void tambah_edge(int u, int v) {
        adj[u].push_back(v);
        if (!berarah) {
            adj[v].push_back(u); // 🔥 otomatis tambah edge balik
        }
    }

    vector<int> bfs(int start) {
        set<int> visited;
        queue<int> q;
        vector<int> urutan;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            urutan.push_back(node);

            vector<int> tetangga = adj[node];
            sort(tetangga.begin(), tetangga.end());

            for (int t : tetangga) {
                if (visited.find(t) == visited.end()) {
                    visited.insert(t);
                    q.push(t);
                }
            }
        }

        return urutan;
    }

    void dfs_helper(int node, set<int>& visited, vector<int>& urutan) {
        visited.insert(node);
        urutan.push_back(node);

        vector<int> tetangga = adj[node];
        sort(tetangga.begin(), tetangga.end());

        for (int t : tetangga) {
            if (visited.find(t) == visited.end()) {
                dfs_helper(t, visited, urutan);
            }
        }
    }

    vector<int> dfs(int start) {
        set<int> visited;
        vector<int> urutan;
        dfs_helper(start, visited, urutan);
        return urutan;
    }
};

int main() {
    Graf g(false); // 🔥 tidak berarah

    // tambah node
    for (int i = 0; i < 7; i++) {
        g.tambah_node(i);
    }

    // edges
    vector<pair<int,int>> edges = {
        {0,1},{0,3},{2,0},{2,3},{2,4},{2,6},
        {3,1},{4,5},{4,6},{5,2},{6,3}
    };

    for (auto e : edges) {
        g.tambah_edge(e.first, e.second);
    }

    // BFS
    vector<int> bfs_result = g.bfs(0);
    cout << "BFS dari 0: ";
    for (int x : bfs_result) cout << x << " ";
    cout << endl;

    // DFS
    vector<int> dfs_result = g.dfs(0);
    cout << "DFS dari 0: ";
    for (int x : dfs_result) cout << x << " ";
    cout << endl;

    return 0;
}