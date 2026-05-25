#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct produk
struct Produk {
    string nama;
};

// 1. Sequential Search O(n)
int sequential_search(vector<Produk> &produk, string target) {
    for (int i = 0; i < produk.size(); i++) {
        if (produk[i].nama == target) {
            return i;
        }
    }
    return -1;
}

// 2. Binary Search O(log n)
// Syarat: data harus sudah diurutkan
int binary_search_produk(vector<Produk> &produk, string target) {
    int kiri = 0;
    int kanan = produk.size() - 1;

    while (kiri <= kanan) {
        int mid = (kiri + kanan) / 2;

        if (produk[mid].nama == target) {
            return mid;
        } else if (produk[mid].nama < target) {
            kiri = mid + 1;
        } else {
            kanan = mid - 1;
        }
    }
    return -1;
}

// Comparator untuk sorting
bool urutNama(Produk a, Produk b) {
    return a.nama < b.nama;
}

int main() {
    vector<Produk> produk = {
        {"Laptop"}, {"Mouse"}, {"Keyboard"}, {"Monitor"},
        {"Printer"}, {"Scanner"}, {"Speaker"}, {"Webcam"}
    };

    string target = "Monitor";

    // Sequential Search
    int hasilSeq = sequential_search(produk, target);

    // Urutkan dulu untuk Binary Search
    sort(produk.begin(), produk.end(), urutNama);

    int hasilBin = binary_search_produk(produk, target);

    cout << "=== PENCARIAN PRODUK E-COMMERCE ===\n";

    if (hasilSeq != -1)
        cout << "Sequential Search: Produk ditemukan di index " << hasilSeq << endl;
    else
        cout << "Sequential Search: Produk tidak ditemukan\n";

    if (hasilBin != -1)
        cout << "Binary Search: Produk ditemukan di index " << hasilBin << endl;
    else
        cout << "Binary Search: Produk tidak ditemukan\n";

    return 0;
}