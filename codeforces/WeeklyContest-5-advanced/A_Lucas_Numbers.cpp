#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

#define int long long
const int md = 1e9 + 7;
int f(int n)
{

    if (n == 1)
    {
        return 1;
    }

    if (n == 0)
    {
        return 2;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int a = f(n - 1);
    int b = f(n - 2);
    return dp[n] = (a + b) % md;
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