#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, cx, cy;
    cin >> n >> k >> cx >> cy;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        int c = (cx - a) * (cx - a);
        int d = (cy - b) * (cy - b);
        pq.push({c + d, {a, b}});

        if (i >= k)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        cout << pq.top().second.first << " " << pq.top().second.second << endl;
        pq.pop();
    }

    return 0;
}