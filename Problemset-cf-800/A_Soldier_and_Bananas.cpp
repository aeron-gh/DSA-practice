#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n, w;
    cin >> k >> n >> w;
    int tc = 0;
    for (int i = 1; i <= w; i++)
    {
        tc += i * k;
    }
    if (tc <= n)
    {
        cout << 0;
        return 0;
    }
    
    cout << tc - n;
    return 0;
}