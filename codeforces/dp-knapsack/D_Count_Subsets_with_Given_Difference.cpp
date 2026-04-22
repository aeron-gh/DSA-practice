#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[50][400];

int f(int pos, int arr[], int n, int t, int cs)
{
    if (pos == n)
    {
        if (t == cs)
        {
            return 1;
        }
        return 0;
    }

    if (dp[pos][cs] != -1)
    {
        return dp[pos][cs];
    }
    int a = 0;
    if (cs + arr[pos] <= t)
    {
        a = f(pos + 1, arr, n, t, cs + arr[pos]);
    }
    int b = f(pos + 1, arr, n, t, cs);

    return dp[pos][cs] = a + b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n, d;
    cin >> n >> d;
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s += a;
        arr[i] = a;
    }
    if ((s + d) % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    int t = (s + d) / 2;
    cout << f(0, arr, n, t, 0);
    return 0;
}