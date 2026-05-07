#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1001][1001];
int f(int i, int curw, vector<int> &wt, vector<int> &val, int w)
{
    if (i == val.size())
    {
        return 0;
    }
    if (dp[i][curw] != -1)
    {
        return dp[i][curw];
    }
    int a = 0;
    if (curw + wt[i] <= w)
    {
        a = val[i] + f(i + 1, curw + wt[i], wt, val, w);
    }

    int b = f(i + 1, curw, wt, val, w);
    return dp[i][curw] = max(a, b);
}

vector<int> ans;
void recover(int i, int curw, vector<int> &wt, vector<int> &val, int w)
{
    if (i == val.size())
    {
        return;
    }

    int a = 0;
    if (curw + wt[i] <= w)
    {
        a = val[i] + f(i + 1, curw + wt[i], wt, val, w);
    }
    int b = f(i + 1, curw, wt, val, w);

    if (a > b)
    {
        ans.push_back(i);
        recover(i + 1, curw + wt[i], wt, val, w);
    }
    else
    {

        recover(i + 1, curw, wt, val, w);
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin >> n >> w;
    vector<int> wt(n);
    vector<int> val(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, wt, val, w) << endl;
    recover(0, 0, wt, val, w);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}