#include <iostream>
#include <string>
using namespace std;

int main() {
    string target = "123"; // password yang dicari
    string tebakan;

    cout << "=== BRUTE FORCE PASSWORD ===" << endl;

    int percobaan = 0;

    // mencoba dari 000 sampai 999
    for (int i = 0; i <= 999; i++) {
        // format jadi 3 digit (contoh: 7 -> 007)
        if (i < 10)
            tebakan = "00" + to_string(i);
        else if (i < 100)
            tebakan = "0" + to_string(i);
        else
            tebakan = to_string(i);

        percobaan++;

        cout << "Mencoba: " << tebakan << endl;

        if (tebakan == target) {
            cout << "\nPassword ditemukan: " << tebakan << endl;
            cout << "Jumlah percobaan: " << percobaan << endl;
            break;
        }
    }

    return 0;
}