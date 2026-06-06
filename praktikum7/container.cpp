#include <iostream>
using namespace std;

int kapasitas = 100;

int berat[] = {40, 35, 30, 20, 15};
string nama[] = {"A", "B", "C", "D", "E"};

int n = 5;

int bestWeight = 0;
bool bestSolution[5];

void backtracking(int idx,
                  int currentWeight,
                  bool selected[])
{
    // update solusi terbaik 
    if (currentWeight > bestWeight &&
        currentWeight <= kapasitas)
    {
        bestWeight = currentWeight;

        for(int i=0;i<n;i++)
            bestSolution[i] = selected[i];
    }

    // finish
    if(idx == n)
        return;

    // pilih barang
    if(currentWeight + berat[idx] <= kapasitas)
    {
        selected[idx] = true;

        backtracking(
            idx + 1,
            currentWeight + berat[idx],
            selected
        );
    }

    // backtrack (tidak pilih barang)
    selected[idx] = false;

    backtracking(
        idx + 1,
        currentWeight,
        selected
    );
}

int main()
{
    bool selected[5] = {false};

    backtracking(0, 0, selected);

    cout << "Barang yang dipilih:\n";

    for(int i=0;i<n;i++)
    {
        if(bestSolution[i])
        {
            cout << nama[i]
                 << " (" << berat[i]
                 << " kg)\n";
        }
    }

    cout << "\nTotal Berat = "
         << bestWeight
         << " kg\n";

    return 0;
}