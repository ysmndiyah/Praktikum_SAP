#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    // Validasi sederhana
    if(n <= 0 || n > 100) {
        cout << "Jumlah data tidak valid!" << endl;
        return 0;
    }

    int data[100];

    cout << "Masukkan data:\n";
    for(int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    // Inisialisasi nilai terbesar
    int maks = data[0];
    int index = 0;

    // Proses brute force (bandingkan semua elemen)
    for(int i = 1; i < n; i++) {
        if(data[i] > maks) {
            maks = data[i];
            index = i;
        }
    }

    // Output hasil
    cout << "\nNilai terbesar adalah: " << maks << endl;
    cout << "Ditemukan pada index ke: " << index << endl;

    return 0;
}