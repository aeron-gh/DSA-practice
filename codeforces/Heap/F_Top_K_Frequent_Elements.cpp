#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto a : mp)
    {
        pq.push({a.second, a.first});
        k--;
        if (k < 0)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
