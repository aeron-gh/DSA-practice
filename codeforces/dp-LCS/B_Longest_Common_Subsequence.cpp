#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int f(int i, int j, string s, string t)
{
    if (i == s.size() || j == t.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int x = 0;
    if (s[i] == t[j])
    {
        x = 1 + f(i + 1, j + 1, s, t);
    }
    else
    {
        int a = f(i + 1, j, s, t);
        int b = f(i, j + 1, s, t);
        x = max(a, b);
    } 
    return dp[i][j] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, s, t);
    return 0;
}