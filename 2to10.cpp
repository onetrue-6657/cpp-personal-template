#include <bits/stdc++.h>
using namespace std;

int binToDec(string bin)
{
    int dec = 0;
    int base = 1; // 2^0

    for (int i = bin.length() - 1; i >= 0; i--)
    {
        if (bin[i] == '1')
        {
            dec += base;
        }
        base *= 2;
    }

    return dec;
}

int main()
{
    string bin;
    cin >> bin;
    cout << binToDec(bin) << endl;
    return 0;
}