#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];
int f(int i, int arr[], int n)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int a = arr[i] + f(i + 2, arr, n);
    int b = f(i + 1, arr, n);

    return dp[i] = max(a, b);
}

vector<int> ans;
void recover(int i, int arr[], int n)
{
    if (i >= n)
    {
        return;
    }

    int a = arr[i] + f(i + 2, arr, n);
    int b = f(i + 1, arr, n);
    if (a > b)
    {
        ans.push_back(i);
        recover(i + 2, arr, n);
    }
    else
    {
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