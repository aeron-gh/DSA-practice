#include <bits/stdc++.h>
using namespace std;

int dp[100001][6];

#define int long long
int f(int pos, int last, int arr[], int n)
{

    if (pos == n)
    {
        return 0;
    }

    if (dp[pos][last] != -1)
    {
        return dp[pos][last];
    }

    int z = INT_MAX;

    int a = 1 + f(pos + 1, 0, arr, n);

    if (arr[pos] == 1 and last != 1)
    {
        int b = f(pos + 1, 1, arr, n);
        z = b;
    }

    if (arr[pos] == 2 and last != 2)
    {
        int c = f(pos + 1, 2, arr, n);
        z = c;
    }

    if (arr[pos] == 3)
    {
        if (last != 1)
        {
            int e = f(pos + 1, 1, arr, n);
            z = min(z, e);
        }
        if (last != 2)
        {
            int g = f(pos + 1, 2, arr, n);
            z = min(z, g);
        }
    }

    return dp[pos][last] = min(z, a);
}

signed main()
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
    cout << f(0, 0, arr, n);
    return 0;
}