#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;

    int n = 100001;
    vector<bool> vec(n + 1, true);
    vec[0] = false;
    vec[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (vec[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                vec[j] = false;
            }
        }
    }

    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    vector<pair<int, int>> pr;
    for (int i = 0; i < k; i++)
    {
        if (vec[arr[i]] == true)
        {
            cnt++;
        }
    }

    pr.push_back({cnt, 0});
    int ans = cnt;
    int st = 0;
    int en = k - 1;

    for (int i = k; i < n; i++)
    {
        if (vec[arr[i]] == true)
        {
            cnt++;
        }
        if (vec[arr[i - k]] == true)
        {
            cnt--;
        }
        pr.push_back({cnt, i - k + 1});
        ans = max(cnt, ans);
    }

    for (int i = 0; i < pr.size(); i++)
    {
        if (pr[i].first == ans)
        {
            for (int j = pr[i].second; j < pr[i].second + k; j++)
            {
                cout << arr[j] << " ";
            }
            return 0;
        }
    }

    return 0;
}