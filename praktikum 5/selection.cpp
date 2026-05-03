#include <iostream>
#include <vector>
using namespace std;

void selection_sort_dc(vector<int>& arr, int start, int n) {
    if (n <= 1) return;

    int min_idx = start;

    // Cari elemen terkecil di arr[start..]
    for (int i = start + 1; i < arr.size(); i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }

    // Tukar
    swap(arr[start], arr[min_idx]);

    // Rekursi ke sisa array
    selection_sort_dc(arr, start + 1, n - 1);
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    selection_sort_dc(arr, 0, arr.size());

    cout << "Sorted: ";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}