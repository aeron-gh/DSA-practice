#include <bits/stdc++.h>
using namespace std;
string ans;

int f(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (i == arr.size() - 1 and j == arr[0].size() - 1)
    {
        return arr[i][j];
    }

    if (i >= arr.size() || j >= arr[0].size())
    {
        return 1e9;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int a = arr[i][j] + f(i, j + 1, arr, dp);
    int b = arr[i][j] + f(i + 1, j, arr, dp);
    return dp[i][j] = min(a, b);
}

void recover(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (i == arr.size() - 1 and j == arr[0].size() - 1)
    {
        return;
    }

    if (i >= arr.size() || j >= arr[0].size())
    {
        return;
    }
    
    int a = arr[i][j] + f(i, j + 1, arr, dp);
    int b = arr[i][j] + f(i + 1, j, arr, dp);

    if(a < b)
    {
        ans += 'R';
        recover(i, j + 1, arr, dp);
    }
    else
    {
        ans += 'D';
        recover(i + 1, j, arr, dp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    cout << f(0, 0, arr, dp) << endl;
    recover(0, 0, arr, dp);
    cout << ans;
    return 0;
}