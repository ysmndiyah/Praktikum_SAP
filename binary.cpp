#include <iostream>
using namespace std;

int main() {

    int data[5] = {1, 3, 5, 7, 9};
    int cari;

    cout << "Data: ";
    for(int i = 0; i < 5; i++) {
        cout << data[i] << " ";
    }

    cout << "\nMasukkan angka yang dicari: ";
    cin >> cari;

    int kiri = 0;
    int kanan = 4;
    int tengah;
    bool ditemukan = false;

    while(kiri <= kanan) {

        tengah = (kiri + kanan) / 2;

        if(data[tengah] == cari) {
            cout << "Data ditemukan di index ke-" << tengah << endl;
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
        cout << "Data tidak ditemukan!" << endl;
    }

    return 0;
}