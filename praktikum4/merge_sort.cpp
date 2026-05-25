#include <iostream>
using namespace std;

// fungsi untuk menggabungkan (combine)
void merge(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// fungsi utama divide & conquer
void mergeSort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;

        // divide
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);

        // combine
        merge(arr, kiri, tengah, kanan);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Data sebelum diurutkan:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    mergeSort(arr, 0, n - 1);

    cout << "\n\nData setelah diurutkan:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}