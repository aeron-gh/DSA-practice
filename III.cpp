#include <bits/stdc++.h>
using namespace std;

int dp[100001][2][2];
int f(int pos, int arr[], int n, bool take, int transactionsNO)
{
    if (pos == n or transactionsNO == 2)
    {
        return 0;
    }

    if (dp[pos][take][transactionsNO] != -1)
    {
        return dp[pos][take][transactionsNO];
    }

    int z = 0;
    if (take == false)
    {
        int a = -arr[pos] + f(pos + 1, arr, n, true, transactionsNO);
        int b = f(pos + 1, arr, n, false, transactionsNO);
        z = max(a, b);
    }
    else
    {
        int a = arr[pos] + f(pos + 1, arr, n, false, transactionsNO + 1);
        int b = f(pos + 1, arr, n, true, transactionsNO);
        z = max(a, b);
    }

    return dp[pos][take][transactionsNO] = z;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, arr, n, false, 0);

    return 0;
}