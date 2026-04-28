#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];
int f(int pos, int arr[], int n)
{
    if (pos >= n)
    {
        return 0;
    }

    if (dp[pos] != -1)
    {
        return dp[pos];
    }
   
    int a = arr[pos] + f(pos + arr[pos] + 1, arr, n);
    int b = f(pos + 1, arr, n);
    return dp[pos] = max(a, b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << f(0, arr, n);
    return 0;
}