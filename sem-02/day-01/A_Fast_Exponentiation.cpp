#include <bits/stdc++.h>
using namespace std;
#define int long long

long long m = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long x, n;
    cin >> x >> n;

    // int ans = 1;
    // x = x % m;
    // while (n > 0)
    // {
    //     if (n & 1)
    //     {
    //         ans = (ans * x) % m;
    //     }

    //     x = (x * x) % m;
    
    //     n = n >> 1;
    // }
    // cout << ans;
    long long a = pow(x, n);
    cout << a % m;
    return 0;
}