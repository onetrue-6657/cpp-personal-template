#include <bits/stdc++.h>
using namespace std;

void dod(int n)
{
    int i;
    if (n == 0)
        return;
    dod(n / 2);
    cout << n / 2;
}

int main()
{
    int n;
    cin >> n;
    dod(n);
}