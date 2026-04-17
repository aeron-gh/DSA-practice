#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];

int f(int pos, int arr[], int n)
{
    if (pos == n - 1)
    {
        return 0;
    }

    if (dp[pos] != -1)
    {
        return dp[pos];
    } 

    int a = abs((arr[pos] - arr[pos + 1])) + f(pos + 1, arr, n);
    int b = (pos + 2 < n) ? abs((arr[pos] - arr[pos + 2])) + f(pos + 2, arr, n) : INT64_MAX;

    return dp[pos] = min(a, b);
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

    cout << f(0, arr, n);
    return 0;
}