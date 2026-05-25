#include <iostream>
#include <algorithm>
using namespace std;

// fungsi untuk urutkan dari terbesar ke terkecil
bool descending(int a, int b) {
    return a > b;
}

void greedyCoin(int koin[], int n, int uang) {
    // urutkan koin
    sort(koin, koin + n, descending);

    int jumlah = 0;

    cout << "Rincian penukaran uang Rp " << uang << ":\n";

    for (int i = 0; i < n; i++) {
        while (uang >= koin[i]) {
            uang -= koin[i];
            cout << "- 1 keping Rp " << koin[i] << endl;
            jumlah++;
        }
    }

    if (uang == 0) {
        cout << "\nTotal keping: " << jumlah << endl;
    } else {
        cout << "\nSisa uang: Rp " << uang << endl;
    }
}

int main() {
    int koin[] = {100, 500, 1000, 2000, 5000, 10000};
    int n = sizeof(koin) / sizeof(koin[0]);
    int uang;

    cout << "=== GREEDY PENUKARAN UANG ===\n";
    cout << "Masukkan jumlah uang: Rp ";
    cin >> uang;

    greedyCoin(koin, n, uang);

    return 0;
}