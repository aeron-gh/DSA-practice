#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
#define int long long

bool f(int i, int curS, vector<int> &arr, int x)
{
    if (i == arr.size())
    {
        return curS == x;
    }
    if (dp[i][curS] != -1)
    {
        return dp[i][curS];
    }
    bool a = false;
    if (curS + arr[i] <= x)
    {
        a = f(i + 1, curS + arr[i], arr, x);
    }
    bool b = f(i + 1, curS, arr, x);
    return dp[i][curS] = a or b;
}

vector<int> ans;

void recover(int i, int curS, vector<int> &arr, int x)
{
    if (i == arr.size())
    {
        return;
    }

    bool a = false;
    if (curS + arr[i] <= x)
    {
        a = f(i + 1, curS + arr[i], arr, x);
    }
    bool b = f(i + 1, curS, arr, x);
    if (a)
    {
        ans.push_back(i);
        recover(i + 1, curS + arr[i], arr, x);
    }
    else if (b)
    {
        recover(i + 1, curS, arr, x);
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof dp);
    bool a = f(0, 0, arr, x); // 
    if (a)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    recover(0, 0, arr, x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}