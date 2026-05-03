#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[1001][1001];

int f(int i, int j, string &s, string &t)
{
    if (j == t.size())
    {
        return 1;
    }
    if (i == s.size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int b = 0;
    int a = f(i + 1, j, s, t);
    if (s[i] == t[j])
    {
        b = f(i + 1, j + 1, s, t);
    }

    return dp[i][j] = a + b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    string s, t;
    cin >> s >> t;
    cout << f(0, 0, s, t);
    return 0;
}