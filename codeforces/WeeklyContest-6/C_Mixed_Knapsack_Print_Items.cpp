#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[201][2001];

int f(int i, int cw, int w, vector<int> &wt, vector<int> &val, vector<int> &t)
{
    if (val.size() == i)
    {
        return 0;
    }
    if (dp[i][cw] != -1)
    {
        return dp[i][cw];
    }
    int a = f(i + 1, cw, w, wt, val, t);
    int b = -1e9;
    if (cw + wt[i] <= w)
    {
        if (t[i] == 1)
        {
            b = val[i] + f(i, cw + wt[i], w, wt, val, t);
        }
        else
        {
            b = val[i] + f(i + 1, cw + wt[i], w, wt, val, t);
        }
    }

    return dp[i][cw] = max(a, b);
}

vector<int> ans;
void recover(int i, int cw, int w, vector<int> &wt, vector<int> &val, vector<int> &t)
{
    if (val.size() == i)
    {
        return;
    }

    int a = f(i + 1, cw, w, wt, val, t);
    int b = -1e9;
    if (cw + wt[i] <= w)
    {
        if (t[i] == 1)
        {
            b = val[i] + f(i, cw + wt[i], w, wt, val, t);
        }
        else
        {
            b = val[i] + f(i + 1, cw + wt[i], w, wt, val, t);
        }
    }

    if (a > b)
    {
        recover(i + 1, cw, w, wt, val, t);
    }
    else
    {
        ans.push_back(i);
        if (t[i] == 1)
        {
            recover(i, cw + wt[i], w, wt, val, t);
        }
        else
        {
            recover(i + 1, cw + wt[i], w, wt, val, t);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n), t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    memset(dp, -1, sizeof dp);
    cout << f(0, 0, w, wt, val, t) << endl;
    recover(0, 0, w, wt, val, t);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}