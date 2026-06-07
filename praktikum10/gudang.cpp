#include <iostream>
#include <string>

using namespace std;

int* computeFail(string pattern)
{
    int* fail = new int[pattern.length()];

    fail[0] = 0;

    int i = 1;
    int j = 0;

    while(i < pattern.length())
    {
        if(pattern[i] == pattern[j])
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

int KMPMatch(string text, string pattern)
{
    int* fail = computeFail(pattern);

    int i = 0;
    int j = 0;

    while(i < text.length())
    {
        if(text[i] == pattern[j])
        {
            if(j == pattern.length() - 1)
                return i - j;

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
    string lokasiGudang =
        "WH-A01 WH-A02 WH-B01 WH-C03 WH-D05";

    string cariLokasi = "WH-C03";

    int posisi =
        KMPMatch(lokasiGudang, cariLokasi);

    if(posisi != -1)
    {
        cout << "Lokasi ditemukan pada indeks ke-"
             << posisi << endl;
    }
    else
    {
        cout << "Lokasi tidak ditemukan"
             << endl;
    }

    return 0;
}