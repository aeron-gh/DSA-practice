#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

bool f(int pos, int cs, int arr[], int n, int k)
{
    if (pos == n)
    {
        return cs == k;
    }

    if (dp[pos][cs] != -1)
    {
        return dp[pos][cs];
    }
    bool a = false;
    if (cs + arr[pos] <= k)
    {
        a = f(pos, cs + arr[pos], arr, n, k);
    }

    bool b = f(pos + 1, cs, arr, n, k);

    return dp[pos][cs] = a or b;
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
    bool a = f(0, 0, arr, n, k);
    if (a)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}