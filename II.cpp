#include <bits/stdc++.h>
using namespace std;

int dp[30001][2];
int f(int pos, int arr[], bool take, int n)
{
    if (pos == n)
    {
        return 0;
    }
    if (dp[pos][take] != -1)
    {
        return dp[pos][take];
    }
    int a = 0;
    if (take == false)
    {
        int b = -arr[pos] + f(pos + 1, arr, true, n);
        int c = f(pos + 1, arr, false, n);
        a = max(b, c);
    }
    else
    {
        int b = f(pos + 1, arr, true, n);
        int c = arr[pos] + f(pos + 1, arr, false, n);
        a = max(b, c);
    }

    return dp[pos][take] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << f(0, arr, false, n);
    return 0;
}