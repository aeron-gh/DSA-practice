#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> leftMax(vector<int> vec)
{
    int n = vec.size();
    vector<int> ans(n);
    stack<int> sta;
    for (int i = 0; i < n; i++)
    {
        while (!sta.empty() and vec[sta.top()] >= vec[i])
        {
            sta.pop();
        }
        if (sta.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = sta.top();
        }
        sta.push(i);
    }
    return ans;
}

vector<int> rightMax(vector<int> vec)
{
    int n = vec.size();
    vector<int> ans(n);
    stack<int> sta;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!sta.empty() and vec[sta.top()] >= vec[i])
        {
            sta.pop();
        }
        if (sta.empty())
        {
            ans[i] = n;
        }
        else
        {
            ans[i] = sta.top();
        }
        sta.push(i);
    }
    return ans;
}

int maxiRect(vector<int> &vec)
{
    int ans = 0;
    vector<int> leftmax = leftMax(vec);
    vector<int> rightmax = rightMax(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        ans = max(((rightmax[i] - leftmax[i] - 1) * vec[i]), ans);
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> vec(m);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '0')
            {
                vec[j] = 0;
            }
            else
            {
                vec[j]++;
            }
        }
        int a = maxiRect(vec);
        ans = max(ans, a);
    }

    cout << ans;

    return 0;
}