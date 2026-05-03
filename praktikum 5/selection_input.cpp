#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selection_sort(arr);

    cout << "Hasil setelah diurutkan (Sorted): ";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}