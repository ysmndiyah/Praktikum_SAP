#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int id;
    int cost;

    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {

    vector<vector<pair<int,int>>> graph(4);

    graph[0].push_back({1,2});
    graph[0].push_back({2,5});
    graph[1].push_back({3,3});
    graph[2].push_back({3,1});

    priority_queue<Node> pq;
    vector<int> dist(4, 1e9);

    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty()) {

        Node cur = pq.top();
        pq.pop();

        for(auto next : graph[cur.id]) {

            int v = next.first;
            int w = next.second;

            if(dist[v] > dist[cur.id] + w) {

                dist[v] = dist[cur.id] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    cout << "Jarak Terpendek Gudang ke Pelanggan = "
         << dist[3] << " km" << endl;

    return 0;
}