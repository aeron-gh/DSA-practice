#include <bits/stdc++.h>
using namespace std;
#define int long long

enum t
{
    buy,
    sell
};

enum prev
{
    x,
    y,
    z,
    none
};

int dp[200001][5];

int f(int i, int t, int prev, vector<vector<int>> &vec)
{
    if (i == vec[0].size())
    {
        return 0;
    }
    int &p = dp[i][prev];
    if (p != -1)
    {
        return p;
    }
    int b = f(i + 1, t, prev, vec);
    int z = INT_MIN;
    if (t == buy)
    {
        for (int j = 0; j < 3; j++)
        {
            int a = -vec[j][i] + f(i + 1, sell, j, vec);
            z = max(a, z);
        }
    }
    else
    {
        for (int j = 0; j < 3; j++)
        {
            if (prev != j)
            {
                int a = vec[j][i] + f(i + 1, buy, none, vec);
                z = max(a, z);
            }
        }
    }

    return p = max(b, z);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> vec(3, vector<int>(n));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            vec[i][j] = a;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, buy, none, vec);
    return 0;
}