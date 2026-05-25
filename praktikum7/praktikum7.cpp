#include <iostream>
using namespace std;

const int V = 4;

// Mengecek apakah warna aman digunakan
bool isSafe(int node, int graph[V][V], int color[], int c)
{
    for(int i = 0; i < V; i++)
    {
        if(graph[node][i] && color[i] == c)
            return false;
    }

    return true;
}

// Fungsi backtracking
bool graphColoring(int graph[V][V], int m, int color[], int node)
{
    // Semua node sudah diberi warna
    if(node == V)
        return true;

    // Coba semua warna
    for(int c = 1; c <= m; c++)
    {
        // Cek apakah warna aman
        if(isSafe(node, graph, color, c))
        {
            color[node] = c;

            // Rekursi ke node berikutnya
            if(graphColoring(graph, m, color, node + 1))
                return true;

            // Backtracking
            color[node] = 0;
        }
    }

    return false;
}

int main()
{
    int graph[V][V] =
    {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int color[V] = {0};

    int m = 3;

    if(graphColoring(graph, m, color, 0))
    {
        cout << "Solusi ditemukan:\n\n";

        for(int i = 0; i < V; i++)
        {
            cout << "Node " << i
                 << " = Warna "
                 << color[i] << endl;
        }
    }
    else
    {
        cout << "Tidak ada solusi";
    }

    return 0;
}