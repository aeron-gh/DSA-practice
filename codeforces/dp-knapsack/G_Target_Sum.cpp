#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1001][2001];
int f(int pos, int cs, int arr[], int n, int k)
{
    if (pos == n)
    {
        return cs == k;
    }

    if (dp[pos][cs + 1000] != -1)
    {
        return dp[pos][cs + 1000];
    }
    int a = f(pos + 1, cs + arr[pos], arr, n, k);
    int b = f(pos + 1, cs - arr[pos], arr, n, k);
    return dp[pos][cs + 1000] = a + b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, arr, n, k);

    return 0;
}