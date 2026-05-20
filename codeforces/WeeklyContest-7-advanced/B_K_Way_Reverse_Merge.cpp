#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> nv;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            nv.push_back(a);
        }
        if (nv[0] < nv[k - 1])
        {
            reverse(nv.begin(), nv.end());
        }
        // for (int i = 0; i < nv.size(); i++)
        // {
        //     cout << nv[i] << " ";
        // }
        // cout << endl;
        vec.push_back(nv);
    }

    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({vec[i][0], {i, 0}});
       
        
    }

    while (!pq.empty())
    {
        cout << pq.top().first << " ";
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if (vec[a].size() <= b + 1)
        {
        }
        else
        {
            pq.push({vec[a][b + 1], {a, b + 1}});
        }
    }

    return 0;
}