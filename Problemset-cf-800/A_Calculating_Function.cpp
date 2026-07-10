#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    if (n % 2 == 0)
    {
        cout << n / 2;
    }
    else
    {
        cout << (n / 2) - n;
    }
    return 0;
}