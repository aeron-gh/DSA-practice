#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[51][51][51][51];
int f(int i, int j, int k, int l, vector<vector<int>> &vec)
{
    int d = vec[0].size();
    if (i == d or j == d or k == d or l == d)
    {
        return 0;
    }

    if (dp[i][j][k][l] != -1)
    {
        return dp[i][j][k][l];
    }
    int z = 0;
    if (vec[0][i] == vec[1][j] and vec[1][j] == vec[2][k] and vec[2][k] == vec[3][l])
    {
        z = 1 + f(i + 1, j + 1, k + 1, l + 1, vec);
    }
    else
    {
        int a = f(i + 1, j, k, l, vec);
        int b = f(i, j + 1, k, l, vec);
        int c = f(i, j, k + 1, l, vec);
        int e = f(i, j, k, l + 1, vec);
        z = max({a, b, c, e});
    }
    return dp[i][j][k][l] = z;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> vec(4, vector<int>(n));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, 0, 0, vec);
    return 0;
}