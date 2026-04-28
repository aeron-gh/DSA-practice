#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

int f(int pos, int cs, int wei[], int val[], int n, int w)
{
    if (pos == n)
    {
        return 0;
    }
    if (dp[pos][cs] != -1)
    {
        return dp[pos][cs];
    }
    int a = 0;
    if (cs + wei[pos] <= w)
    {
        a = val[pos] + f(pos, cs + wei[pos], wei, val, n, w);
    }
    int b = f(pos + 1, cs, wei, val, n, w);
    return dp[pos][cs] = max(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, k;
    cin >> n >> w;
    int wei[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wei[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    cin >> k;

    int cs = 0;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        a--;

        cs += wei[a];
        ans += val[a];

        // wei[a] = 0;
        // val[a] = 0;
    }
    if (cs > w)
    {
        cout << -1;
        return 0;
    }
    memset(dp, -1, sizeof dp);
    ans += f(0, cs, wei, val, n, w);
    cout << ans;
    return 0;
}