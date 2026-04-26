#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int no;
    cin >> no;
    int pw = 1;
    while (pw <= no)
    {
        pw *= 2;
    }
    pw = pw / 2;

    while (pw > 0)
    {
        if (pw <= no)
        {
            cout << pw << " ";
            no -= pw;
        }
        pw = pw / 2;
    }

    return 0;
}