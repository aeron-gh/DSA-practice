#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int f(int pos, int cs, int arr[], int sz[], int n)
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
    if (cs + sz[pos] <= n)
    {
        a = arr[pos] + f(pos, cs + sz[pos], arr, sz, n);
    }
    int b = f(pos + 1, cs, arr, sz, n);

    return dp[pos][cs] = max(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    int sz[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sz[i] = i + 1;
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, arr, sz, n);
    return 0;
}