#include <bits/stdc++.h>
using namespace std;
#define int long long


int f(int x, int y, vector<vector<int>> &vec, int n, vector<vector<int>> &dp)
{ // tell min sum to go last

    if (x == n - 1)
    {
        return vec[x][y];
    }
    
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    int a = vec[x][y] + f(x + 1, y, vec, n, dp);
    int b = vec[x][y] + f(x + 1, y + 1, vec, n, dp);

    return dp[x][y] = min(a, b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    vector<vector<int>> dp(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int a;
            cin >> a;
            vec[i].push_back(a);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            dp[i].push_back(-1);
        }
    }
    cout << f(0, 0, vec, n, dp);

    return 0;
}