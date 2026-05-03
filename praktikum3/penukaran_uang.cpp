#include <iostream>
#include <algorithm>
using namespace std;

// urutkan dari terbesar ke terkecil
bool urutTurun(int a, int b) {
    return a > b;
}

void greedyPenukaran(int koin[], int n, int uang) {
    sort(koin, koin + n, urutTurun);

    cout << "=== GREEDY COIN CHANGE ===" << endl;
    cout << "Target uang: Rp " << uang << endl;
    cout << "--------------------------" << endl;

    int totalKoin = 0;

    for (int i = 0; i < n; i++) {
        while (uang >= koin[i]) {
            uang -= koin[i];
            cout << "Ambil 1 koin Rp " << koin[i] << endl;
            totalKoin++;
        }

        if (uang == 0) break;
    }

    cout << "--------------------------" << endl;

    if (uang > 0) {
        cout << "Sisa uang tidak dapat ditukar: Rp " << uang << endl;
    } else {
        cout << "Total koin yang digunakan: " << totalKoin << " keping" << endl;
    }
}

int main() {
    // pecahan sesuai kasus (10.000 sampai 100)
    int koin[] = {10000, 5000, 2000, 1000, 500, 200, 100};
    int n = sizeof(koin) / sizeof(koin[0]);

    int uang = 17800;

    greedyPenukaran(koin, n, uang);

    return 0;
}