#include <bits/stdc++.h>
using namespace std;
#define int long long

const int md = 1e9 + 7;
int dp[100001];

int f(int pos, int n, int arr[], int m)
{
    if (pos > n)
    {
        return 0;
    }
    if (arr[pos] == 1)
    {
        return 0;
    }
    if (pos == n)
    {
        return 1;
    }

    if (dp[pos] != -1)
    {
        return dp[pos];
    }

    int a = f(pos + 1, n, arr, m);
    int b = f(pos + 2, n, arr, m);
    int c = f(pos + 3, n, arr, m);

    return dp[pos] = (a + b + c) % md;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr[n + 1] = {0};
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        arr[a] = 1;
    }
    cout << f(0, n, arr, m);
    return 0;
}