#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                cnt++;
            }
        }
        pq.push({cnt, i});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    vector<int> ans;
    while (pq.size() != 0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}