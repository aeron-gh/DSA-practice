#include <bits/stdc++.h>
using namespace std;
int dp[1001][10001];

int f(int pos, int cs, int arr[], int n, int k)
{
    if (pos == n)
    {
        if (k == cs)
        {
            return 0;
        }
        return 1e9;
    }
    if (dp[pos][cs] != -1)
    {
        return dp[pos][cs];
    }
    int a = 1e9;
    if (cs + arr[pos] <= k)
    {
        a = 1 + f(pos, cs + arr[pos], arr, n, k);
    }
    int b = f(pos + 1, cs, arr, n, k);
    return dp[pos][cs] = min(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a = f(0, 0, arr, n, k);
    if (a == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << a;
    }
    return 0;
}