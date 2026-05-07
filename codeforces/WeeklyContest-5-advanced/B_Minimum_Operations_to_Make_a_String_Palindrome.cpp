#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int f(int i, int j, string &s)
{
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int z = 0;
    if (s[i] == s[j])
    {
        int a = f(i + 1, j - 1, s);
        z = a;
    }
    else
    {
        int a = 1 + f(i, j - 1, s);
        int b = 1 + f(i + 1, j, s);
        z = min(a, b);
    }

    return dp[i][j] = z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    memset(dp, -1, sizeof dp);
    cout << f(0, str.size() - 1, str);
    return 0;
}