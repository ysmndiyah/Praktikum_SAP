#include <iostream>
#include <string>

using namespace std;

// Membuat tabel failure function
int* computeFail(string pattern)
{
    int* fail = new int[pattern.length()];

    fail[0] = 0;

    int m = pattern.length();
    int j = 0;
    int i = 1;

    while(i < m)
    {
        if(pattern[j] == pattern[i])
        {
            fail[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = fail[j - 1];
        }
        else
        {
            fail[i] = 0;
            i++;
        }
    }

    return fail;
}

// Algoritma KMP
int KMPMatch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    int* fail = computeFail(pattern);

    int i = 0;
    int j = 0;

    while(i < n)
    {
        if(pattern[j] == text[i])
        {
            if(j == m - 1)
                return i - m + 1;

            i++;
            j++;
        }
        else if(j > 0)
        {
            j = fail[j - 1];
        }
        else
        {
            i++;
        }
    }

    return -1;
}

int main()
{
    string text = "abacaabacabacababa";
    string pattern = "acab";

    cout << "Text    : " << text << endl;
    cout << "Pattern : " << pattern << endl;

    int posisi = KMPMatch(text, pattern);

    if(posisi == -1)
        cout << "Pattern tidak ditemukan" << endl;
    else
        cout << "Pattern ditemukan pada posisi ke-" << posisi << endl;

    return 0;
}