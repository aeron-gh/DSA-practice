#include <bits/stdc++.h>
using namespace std;
#define int long long

const int m = 1e9 + 7;

int dp[1000001];

int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = (f(n - 1) % m + (2 * f(n - 2)) % m) % m;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << f(n);
    return 0;
}