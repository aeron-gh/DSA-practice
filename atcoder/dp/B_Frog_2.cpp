#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];

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

    int mn = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if ((pos + i) >= n)
        {
            break;
        }
        int a = abs((arr[pos] - arr[pos + i])) + f(pos + i, arr, n, k);
        if (a < mn)
        {
            mn = a;
        }
    }

    return dp[pos] = mn;
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