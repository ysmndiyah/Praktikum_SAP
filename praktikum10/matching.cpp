#include <iostream>
#include <string>

using namespace std;

// Failure Function KMP
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

// KMP Search
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
    string dataResi =
        "PKG123 PKG456 PKG789 PKG321";

    string cariResi = "PKG456";

    int posisi =
        KMPMatch(dataResi, cariResi);

    if(posisi != -1)
    {
        cout << "Nomor resi ditemukan pada indeks ke-"
             << posisi << endl;
    }
    else
    {
        cout << "Nomor resi tidak ditemukan"
             << endl;
    }

    return 0;
}