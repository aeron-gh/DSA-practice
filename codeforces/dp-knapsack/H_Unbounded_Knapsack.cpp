#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int f(int pos, int cs, int loot[], int w[], int n, int t)
{
    if (pos == n)
    {
        return 0;
    }

    if(dp[pos][cs] != -1){
        return dp[pos][cs];
    }

    int a = 0;
    if (cs + w[pos] <= t)
    {
        a = loot[pos] + f(pos, cs + w[pos], loot, w, n, t);
    }
    int b = f(pos + 1, cs, loot, w, n, t);

    return dp[pos][cs] = max(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1, sizeof dp);
    int n, t;
    cin >> n >> t;
    int loot[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> loot[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    cout << f(0, 0, loot, w, n, t);
    return 0;
}