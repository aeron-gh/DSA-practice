#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];

int f(int i, int arr[], int n)
{
    if (i >= n - 1)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int a = abs(arr[i + 1] - arr[i]) + f(i + 1, arr, n);
    // int b = 1e9;
    // if (i + 2 < n)
    // {
        int b = abs(arr[i + 2] - arr[i]) + f(i + 2, arr, n);
    // }

    return dp[i] = min(a, b);
}

vector<int> ans;
void recover(int i, int arr[], int n)
{
    if (i >= n - 1)
    {
        ans.push_back(n - 1);
        return;
    }

    int a = abs(arr[i + 1] - arr[i]) + f(i + 1, arr, n);
    int b = 1e9;
    if (i + 2 < n)
    {
        b = abs(arr[i + 2] - arr[i]) + f(i + 2, arr, n);
    }

    if (a > b)
    {
        ans.push_back(i);
        recover(i + 2, arr, n);
    }
    else
    {
        ans.push_back(i);
        recover(i + 1, arr, n);
    }
    return;
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

    cout << f(0, arr, n) << endl;
    recover(0, arr, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}