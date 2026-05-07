#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1001][1001];

int f(int i, int j, string &s, string &t)
{
    if (i == s.size() or j == t.size())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int z = 0;
    if (s[i] == t[j])
    {
        z = 1 + f(i + 1, j + 1, s, t);
    }
    else
    {
        int a = f(i + 1, j, s, t);
        int b = f(i, j + 1, s, t);
        z = max(a, b);
    }

    return dp[i][j] = z;
}

string ans;
void recover(int i, int j, string &s, string &t)
{
    if (i == s.size() or j == t.size())
    {
        return;
    }

    if (s[i] == t[j])
    {
        ans.push_back(s[i]);
        recover(i + 1, j + 1, s, t);
    }
    else
    {
        int a = f(i + 1, j, s, t);
        int b = f(i, j + 1, s, t);
        if (a > b)
        {
            recover(i + 1, j, s, t);
        }
        else
        {
            recover(i, j + 1, s, t);
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    // f(0, 0, s, t);
    recover(0, 0, s, t);
    cout << ans;
    return 0;
}