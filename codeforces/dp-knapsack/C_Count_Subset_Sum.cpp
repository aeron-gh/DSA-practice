#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1001][1001];
const int m = 1e9 + 7;
int f(int pos, int arr[], int n, int k, int cs)
{
    if (pos == n)
    {
        if (cs == k)
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

    if (cs + arr[pos] <= k)
    {
        a = f(pos + 1, arr, n, k, cs + arr[pos]);
    }

    int b = f(pos + 1, arr, n, k, cs);

    return dp[pos][cs] = (a + b) % m;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << f(0, arr, n, k, 0);

    return 0;
}