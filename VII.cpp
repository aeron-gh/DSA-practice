#include <bits/stdc++.h>
using namespace std;

const int BUY = 0;
const int SELL = 1;

int fee = 0;
int dp[50001][2];

int f(int pos, int arr[], int n, int take)
{
    if (pos >= n)
    {
        return 0;
    }

    if (dp[pos][take] != -1)
    {
        return dp[pos][take];
    }

    int z = 0;
    if (take == BUY)
    {
        int a = -fee - arr[pos] + f(pos + 1, arr, n, SELL);
        int b = f(pos + 1, arr, n, BUY);
        z = max(a, b);
    }
    else
    {
        int a = arr[pos] + f(pos + 1, arr, n, BUY);
        int b = f(pos + 1, arr, n, SELL);
        z = max(a, b);
    }

    return dp[pos][take] = z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> fee;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof dp);
    cout << f(0, arr, n, BUY);
    return 0;
}