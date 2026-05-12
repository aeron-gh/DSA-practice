#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000001];
int f(int pos, vector<int> &vec, int n)
{
    if (pos == n)
    {
        return 0;
    }

    if (pos > n)
    {
        return 1e9;
    }
    if (dp[pos] != -1)
    {
        return dp[pos];
    }
    
    int z = 1e9;
    for (int i = 1; i <= 6; i++)
    {
        int next = pos + i;

        if (next <= n)
        {
            if (vec[next] != -1)
            {
                continue;
            }
            z = min(z, 1 + f(next, vec, n));
        }
    }
    
    return dp[pos] = z;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> vec(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        vec[x] = 1;
    }
    memset(dp, -1, sizeof dp);
    int ans = f(0, vec, n);

    if (ans >= 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}