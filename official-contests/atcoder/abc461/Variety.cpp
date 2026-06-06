#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;

    vector<priority_queue<int>> mh(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        mh[a].push(b);
    }

    int ans = 0;

    vector<pair<int, int>> v;
    for (int j = 0; j < n; j++)
    {
        auto &b = mh[j];
        if (!b.empty())
        {
            int nt = b.top();
            v.push_back({nt, j});
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        ans += v[i].first;
        mh[v[i].second].pop();
    }

    // for (int i = 0; i < k - m; i++)
    // {
    //     int t = -1;
    //     int s = -1;
    //     for (int j = 0; j < n; j++)
    //     {
    //         auto b = mh[j];
    //         if (!b.empty())
    //         {
    //             int nt = b.top();
    //             if (nt > t)
    //             {
    //                 t = nt;
    //                 s = j;
    //             }
    //         }
    //     }
    //     ans += t;
    //     mh[s].pop();
    // }

    vector<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!mh[i].empty())
        {
            s.push_back(mh[i].top());
            mh[i].pop();
        }
    }

    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    for (int i = 0; i < k - m; i++)
    {
        ans += s[i];
    }

    cout << ans;
    return 0;
}