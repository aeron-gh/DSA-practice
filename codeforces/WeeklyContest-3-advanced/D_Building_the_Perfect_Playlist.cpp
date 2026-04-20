#include <bits/stdc++.h>
using namespace std;

#define int long long

// int const sz = 1001;
// int dp[sz][sz];

int f(int x, int y, vector<vector<int>> &vec, int n, vector<vector<int>> &dp)
{
    if (x == n - 1)
    {
        return vec[x][y];
    }

    if (dp[x][y] != INT64_MIN)
    {
        return dp[x][y];
    }

    int c = INT64_MIN;
    int a = vec[x][y] + f(x + 1, y, vec, n, dp);
    int b = vec[x][y] + f(x + 1, y + 1, vec, n, dp);
    if (y - 1 >= 0)
    {
        c = vec[x][y] + f(x + 1, y - 1, vec, n, dp);
    }

    int d = max(a, b);
    return dp[x][y] = max(c, d);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
             dp[i].push_back(INT64_MIN);
        }
    }

    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int a;
            cin >> a;
            vec[i].push_back(a);
        }
    }

    cout << f(0, 0, vec, n, dp);
    return 0;
}