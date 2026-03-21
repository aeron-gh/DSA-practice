#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    if  ((n & 1) == 1)
    {
        cout << "Odd";
    }
    else
    {
        cout << "Even";
    }

    return 0;
}