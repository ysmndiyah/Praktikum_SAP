#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. MANAGEMEN BANDWIDTH (prioritas terbesar dulu)
void bandwidthISP() {
    vector<int> kebutuhan = {50, 20, 80, 30, 10}; // Mbps
    sort(kebutuhan.begin(), kebutuhan.end(), greater<int>());

    int kapasitas = 100;
    int total = 0;

    cout << "\n=== Manajemen Bandwidth ISP (Greedy) ===\n";

    for (int i = 0; i < kebutuhan.size(); i++) {
        if (kapasitas >= kebutuhan[i]) {
            cout << "Alokasi " << kebutuhan[i] << " Mbps\n";
            kapasitas -= kebutuhan[i];
            total++;
        }
    }

    cout << "Sisa bandwidth: " << kapasitas << " Mbps\n";
}

// 2. ROUTING JARINGAN (pilih jarak terdekat)
void routingJaringan() {
    vector<int> jarak = {10, 5, 20, 8, 3};
    sort(jarak.begin(), jarak.end());

    cout << "\n=== Routing Jaringan (Greedy) ===\n";
    cout << "Jalur yang dipilih (terdekat ke terjauh):\n";

    int total = 0;
    for (int i = 0; i < jarak.size(); i++) {
        cout << "Node dengan jarak " << jarak[i] << " km\n";
        total++;
        if (total == 3) break; // simulasi ambil jalur cepat
    }
}

// 3. OPTIMASI RUTE LOGISTIK (nearest neighbor sederhana)
void logistik() {
    vector<int> jarak = {12, 4, 7, 3, 9};
    sort(jarak.begin(), jarak.end());

    cout << "\n=== Optimasi Rute Logistik (Greedy) ===\n";

    int totalJarak = 0;
    for (int i = 0; i < jarak.size(); i++) {
        cout << "Kunjungi lokasi jarak " << jarak[i] << " km\n";
        totalJarak += jarak[i];
    }

    cout << "Total jarak ditempuh: " << totalJarak << " km\n";
}

int main() {
    int pilihan;

    cout << "=== IMPLEMENTASI GREEDY DI SISTEM NYATA ===\n";
    cout << "1. Manajemen Bandwidth ISP\n";
    cout << "2. Routing Jaringan\n";
    cout << "3. Optimasi Rute Logistik\n";
    cout << "Pilih menu: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            bandwidthISP();
            break;
        case 2:
            routingJaringan();
            break;
        case 3:
            logistik();
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }

    return 0;
}