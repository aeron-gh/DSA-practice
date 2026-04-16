#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int sz = 1e6;
int dp[sz + 1];

int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = (f(n - 1) + f(n - 2) + f(n - 3)) % mod;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}