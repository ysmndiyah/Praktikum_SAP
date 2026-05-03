#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Masukkan jumlah data (maks 100): ";
    cin >> n;

    // Validasi input
    if(n > 100 || n <= 0) {
        cout << "Jumlah data tidak valid!" << endl;
        return 0;
    }

    int data[100];

    // Input data
    cout << "Masukkan data:\n";
    for(int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    // Tampilkan sebelum sorting
    cout << "\nData sebelum sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    // 🔹 BUBBLE SORT
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    // Tampilkan setelah sorting
    cout << "\n\nData setelah Bubble Sort:\n";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    // 🔹 BINARY SEARCH
    int cari;
    cout << "\n\nMasukkan angka yang ingin dicari: ";
    cin >> cari;

    int kiri = 0;
    int kanan = n - 1;
    int tengah;
    bool ditemukan = false;

    while(kiri <= kanan) {

        tengah = (kiri + kanan) / 2;

        if(data[tengah] == cari) {
            cout << "\nData ditemukan di index ke-" << tengah 
                 << " dengan nilai " << data[tengah] << endl;
            ditemukan = true;
            break;
        }

        else if(data[tengah] < cari) {
            kiri = tengah + 1;
        }

        else {
            kanan = tengah - 1;
        }
    }

    if(!ditemukan) {
        cout << "\nData tidak ditemukan!" << endl;
    }

    return 0;
}