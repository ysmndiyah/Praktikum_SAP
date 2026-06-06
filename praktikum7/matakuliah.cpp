#include <iostream>
using namespace std;

const int V = 5;

// Nama mata kuliah
string matkul[V] = {
    "Algoritma",
    "Basis Data",
    "Kalkulus",
    "Jaringan",
    "Pemrograman"
};

// Mengecek apakah slot waktu aman
bool isSafe(int node, int graph[V][V], int color[], int c)
{
    for(int i = 0; i < V; i++)
    {
        if(graph[node][i] && color[i] == c)
            return false;
    }

    return true;
}

// Algoritma backtracking
bool scheduleExam(int graph[V][V], int m, int color[], int node)
{
    // Semua mata kuliah sudah dijadwalkan
    if(node == V)
        return true;

    // Coba semua slot waktu
    for(int c = 1; c <= m; c++)
    {
        if(isSafe(node, graph, color, c))
        {
            color[node] = c;

            // Rekursi ke node berikutnya
            if(scheduleExam(graph, m, color, node + 1))
                return true;

            // Backtracking
            color[node] = 0;
        }
    }

    return false;
}

int main()
{
    // Matriks konflik mata kuliah 
    int graph[V][V] =
    {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    // Menyimpan slot waktu 
    int color[V] = {0};

    // Jumlah slot waktu
    int m = 3;

    if(scheduleExam(graph, m, color, 0))
    {
        cout << "Jadwal ujian berhasil dibuat:\n\n";

        for(int i = 0; i < V; i++)
        {
            cout << matkul[i]
                 << " -> Slot "
                 << color[i]
                 << endl;
        }
    }
    else
    {
        cout << "Tidak ada jadwal yang valid";
    }

    return 0;
}