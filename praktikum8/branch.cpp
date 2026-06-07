#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 4;

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int minCost = INT_MAX;
vector<int> bestPath;

void tspBranchAndBound(vector<int>& path,
                       vector<bool>& visited,
                       int currentCost)
{
    if(path.size() == N)
    {
        int totalCost =
            currentCost +
            graph[path.back()][0];

        if(totalCost < minCost)
        {
            minCost = totalCost;
            bestPath = path;
        }
        return;
    }

    if(currentCost >= minCost)
        return;

    for(int i = 0; i < N; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            path.push_back(i);

            tspBranchAndBound(
                path,
                visited,
                currentCost +
                graph[path[path.size()-2]][i]
            );

            path.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    vector<int> path;
    vector<bool> visited(N, false);

    path.push_back(0);
    visited[0] = true;

    tspBranchAndBound(path, visited, 0);

    cout << "Rute Distribusi Optimal:\n";

    for(int node : bestPath)
        cout << node << " -> ";

    cout << "0\n";

    cout << "Total Jarak = "
         << minCost << endl;

    return 0;
}