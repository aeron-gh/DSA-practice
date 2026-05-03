#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int f(int i, int j, string s, string t)
{
    if (i == s.size())
    {
        return t.size() - j;
    }

    if (j == t.size())
    {
        return s.size() - i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int z = 0;
    if (s[i] == t[j])
    {
        int a = f(i + 1, j + 1, s, t);
        z = a;
    }
    else
    {
        int a = 1 + f(i + 1, j, s, t);
        int b = 1 + f(i, j + 1, s, t);
        int c = 1 + f(i + 1, j + 1, s, t);

        z = min({a, b, c});
    }
    return dp[i][j] = z;
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