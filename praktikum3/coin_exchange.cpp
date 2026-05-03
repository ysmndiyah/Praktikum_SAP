#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coin_exchange(vector<int> koin_tersedia, int nilai_target) {
    // urutkan dari terbesar ke terkecil
    sort(koin_tersedia.begin(), koin_tersedia.end(), greater<int>());

    vector<int> solusi;
    int sisa = nilai_target;

    for (int denominasi : koin_tersedia) {
        while (sisa >= denominasi) {
            solusi.push_back(denominasi);
            sisa -= denominasi;
        }
    }

    // jika tidak pas 0, berarti tidak ada solusi
    if (sisa != 0) {
        return {};
    }

    return solusi;
}

int main() {
    vector<int> koin = {500, 200, 100, 50, 20, 10, 5, 1};

    vector<int> hasil = coin_exchange(koin, 730);

    cout << "Koin dipilih: ";
    for (int k : hasil) {
        cout << k << " ";
    }
    cout << endl;

    cout << "Jumlah koin: " << hasil.size() << endl;

    return 0;
}