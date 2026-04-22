#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[101][50001];

bool f(int pos, int a, int arr[], int n, int t)
{
    if (pos == n)
    {
        return a == t;
    }
    if (dp[pos][a] != -1)
    {
        return dp[pos][a];
    }
    bool x = false;
    if (a + arr[pos] <= t)
    {
        x = f(pos + 1, a + arr[pos], arr, n, t);
    }
    bool y = f(pos + 1, a, arr, n, t);

    return dp[pos][a] = x or y;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s += a;
        arr[i] = a;
    }

    if (s % 2 != 0)
    {
        cout << "NO";
        return 0;
    }

    f(0, 0, arr, n, s / 2) == true ? cout << "YES" : cout << "NO";
    return 0;
}