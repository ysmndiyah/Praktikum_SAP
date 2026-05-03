#include <iostream>
using namespace std;

int main() {
    int data[5] = {5, 2, 4, 1, 3};
    int n = 5;

    cout << "Data sebelum sorting: ";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    // Bubble Sort
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    cout << "\nData setelah Bubble Sort: ";
    for(int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}