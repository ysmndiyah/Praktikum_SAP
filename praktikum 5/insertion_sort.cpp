#include <iostream>
#include <vector>
using namespace std;

struct Tugas {
    string nama;
    string hari;
    int deadline;
};

// Konversi hari ke angka
int konversiHari(string h) {
    if (h == "senin") return 1;
    if (h == "selasa") return 2;
    if (h == "rabu") return 3;
    if (h == "kamis") return 4;
    if (h == "jumat") return 5;
    if (h == "sabtu") return 6;
    if (h == "minggu") return 7;
    return 0;
}

void insertion_sort(vector<Tugas>& tugas) {
    for (int i = 1; i < tugas.size(); i++) {
        Tugas key = tugas[i];
        int j = i - 1;

        while (j >= 0 && tugas[j].deadline > key.deadline) {
            tugas[j + 1] = tugas[j];
            j--;
        }

        tugas[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah tugas: ";
    cin >> n;

    vector<Tugas> tugas(n);

    for (int i = 0; i < n; i++) {
        cout << "Nama tugas ke-" << i + 1 << ": ";
        cin >> tugas[i].nama;

        cout << "Deadline (hari): ";
        cin >> tugas[i].hari;

        tugas[i].deadline = konversiHari(tugas[i].hari);
    }

    insertion_sort(tugas);

    cout << "\nDaftar Prioritas Tugas:\n";
    for (int i = 0; i < n; i++) {
        cout << tugas[i].nama << " - " << tugas[i].hari << endl;
    }

    return 0;
}