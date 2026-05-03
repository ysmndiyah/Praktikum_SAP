#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Masukkan bilangan: ";
    cin >> n;

    bool prima = true;

    // Cek kondisi awal
    if(n < 2) {
        prima = false;
    } else {
        // Cek pembagi dari 2 sampai n-1
        for(int i = 2; i < n; i++) {
            if(n % i == 0) {
                prima = false;
                break;
            }
        }
    }

    // Output hasil
    if(prima) {
        cout << n << " adalah bilangan prima" << endl;
    } else {
        cout << n << " bukan bilangan prima" << endl;
    }

    return 0;
}