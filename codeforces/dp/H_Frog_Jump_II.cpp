#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000000];
int f(int pos, int arr[], int n, int k)
{
    if (pos == n - 1)
    {
        return 0;
    }

    if (dp[pos] != -1)
    {
        return dp[pos];
    }
    int a = INT64_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (pos + i > n - 1)
        {
            return dp[pos] = a;
        }
        int b = abs(arr[pos] - arr[pos + i]) + f(pos + i, arr, n, k);
        if (b < a)
        {
            a = b;
        }
    }
    return dp[pos] = a;
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
    cout << f(0, arr, n, k);
    return 0;
}