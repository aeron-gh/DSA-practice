#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1001][1001];

int f(int pos, vector<int> &wei, vector<int> &val, int W, int cw)
{
    if (pos == wei.size())
    {
        return 0;
    }
    if (dp[pos][cw] != -1)
    {
        return dp[pos][cw];
    }
    int a = 0;
    if (cw + wei[pos] <= W)
    {
        a = val[pos] + f(pos + 1, wei, val, W, cw + wei[pos]);
    }

    int b = f(pos + 1, wei, val, W, cw);
    return dp[pos][cw] = max(a, b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n, W;
    cin >> n >> W;
    int cw = 0;
    vector<int> wei(n);
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wei[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cout << f(0, wei, val, W, cw);
    return 0;
}