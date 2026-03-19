#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int no;
    cin >> no;
    if (no == 0)
    {
        cout << 0;
        return 0;
    }
    int pw = 1;
    while (pw <= no)
    {
        pw *= 2;
    }

    pw /= 2;
    string str;

    while (pw > 0) // no => wrong
    {
        if (no >= pw)
        {
            no -= pw;
            str += '1';
        }
        else
        {
            str += '0';
        }

        pw /= 2;
    }

    cout << str;
    return 0;
}