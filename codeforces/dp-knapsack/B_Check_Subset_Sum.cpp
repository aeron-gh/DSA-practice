#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[201][1001];

bool f(int pos, int arr[], int n, int k, int cs)
{
    if (pos == n)
    {
        if (cs == k)
        {
            return true;
        }
        return false;
    }

    if (dp[pos][cs] != -1)
    {
        return dp[pos][cs];
    }

    bool a = false;

    if (cs + arr[pos] <= k)
    {
        a = f(pos + 1, arr, n, k, cs + arr[pos]);
    }

    bool b = f(pos + 1, arr, n, k, cs);

    return dp[pos][cs] = a or b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (f(0, arr, n, k, 0))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    } 

    return 0;
}