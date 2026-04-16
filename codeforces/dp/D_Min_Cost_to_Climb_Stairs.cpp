#include <bits/stdc++.h>
using namespace std;
#define int long long

const int sz = 1e6 + 1;
int dp[sz];

int f(int pos, vector<int> &arr, int n)
{
    if (pos >= n)
    {
        return 0;
    }
    if (dp[pos] != -1)
    {
        return dp[pos];
    }
    return dp[pos] = arr[pos] + (min(f(pos + 1, arr, n), f(pos + 2, arr, n)));
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << arr[0];
        return 0;
    }
    int a = f(0, arr, n);
    int b = f(1, arr, n);

    cout << min(a, b);
    return 0;
}