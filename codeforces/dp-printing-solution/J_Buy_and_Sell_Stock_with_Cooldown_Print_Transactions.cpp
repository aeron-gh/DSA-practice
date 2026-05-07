#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100001][2];

enum transactions
{
    buy,
    sell
};

int f(int i, int arr[], int t, int n)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i][t] != -1)
    {
        return dp[i][t];
    }
    int x = f(i + 1, arr, t, n);
    int y = 0;

    if (t == buy)
    {
        y = -arr[i] + f(i + 1, arr, sell, n);
    }
    else
    {
        y = arr[i] + f(i + 2, arr, buy, n);
    }
    return dp[i][t] = max(x, y);
}

vector<int> ans;

void recover(int i, int arr[], int t, int n)
{
    if (i >= n)
    {
        return;
    }

    int x = f(i + 1, arr, t, n);
    int y = 0;

    if (t == buy)
    {
        y = -arr[i] + f(i + 1, arr, sell, n);
    }
    else
    {
        y = arr[i] + f(i + 2, arr, buy, n);
    }

    if (x > y)
    {
        recover(i + 1, arr, t, n);
    }
    else
    {
        ans.push_back(i);
        if (t == buy)
        {
            recover(i + 1, arr, sell, n);
        }
        else
        {
            recover(i + 2, arr, buy, n);
        }
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
    cout << f(0, arr, buy, n) << endl;
    recover(0, arr, buy, n);
    cout << ans.size() / 2 << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
        i++;
    }
    return 0;
}