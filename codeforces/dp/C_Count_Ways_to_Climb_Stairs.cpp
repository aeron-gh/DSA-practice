#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int sz = 1e6 + 1;
int dp[sz];

int f(int pos, int n)
{
    if (pos == n)
    {
        return 1;
    }

    if (pos > n)
    {
        return 0;
    }
    
    if (dp[pos] != -1)
    {
        return dp[pos];
    }

    int a = f(pos + 1, n) + f(pos + 2, n);
    dp[pos] = a;

    return a % mod;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << f(0, n);

    return 0;
}