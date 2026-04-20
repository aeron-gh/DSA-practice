#include <bits/stdc++.h>
using namespace std;

#define int long long

int const m = 1e9 + 7;

int dp[1000001];
int f(int pos, int n)
{
    if (pos >= n)
    {
        return 1;
    }
    if (dp[pos] != -1)
    {
        return dp[pos];
    }
    int a = f(pos + 1, n) + f(pos + 2, n);
    dp[pos] = a;
    return a % m;
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