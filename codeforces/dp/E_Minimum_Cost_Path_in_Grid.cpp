#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x, int y, vector<vector<int>> &vec, int n, int m, vector<vector<int>> &dp)
{
    if (x == n - 1 and y == m - 1)
    {
        return vec[x][y];
    }

    if (x >= n || y >= m)
    {
        return INT64_MAX;
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    return dp[x][y] = vec[x][y] + min(f(x + 1, y, vec, n, m, dp), f(x, y + 1, vec, n, m, dp));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    cout << f(0, 0, vec, n, m, dp);

    return 0;
}