#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000001][2];

int f(int pos, int arr[], int n, bool taken)
{
    if (pos >= n)
    {
        return 0;
    }

    if (pos == n - 1)
    {
        if (taken == true)
        {
            return 0;
        }
        return arr[n - 1];
    }

    if (dp[pos][taken] != -1)
    {
        return dp[pos][taken];
    }

    int a = f(pos + 1, arr, n, taken);
    
    int b = arr[pos] + f(pos + 2, arr, n, pos == 0 ? true : taken);

    return dp[pos][taken] = max(a, b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << f(0, arr, n, false);
    return 0;
}