#include <bits/stdc++.h>
using namespace std;

void dfs(int a, vector<int> adj[], vector<bool> &color)
{

    color[a] = true;

    for (auto b : adj[a])
    {
        if (color[b] == false)
        {
            dfs(b, adj, color);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int x;
    cin >> x;

    vector<bool> color(n + 1, 0);
    dfs(x, adj, color);
    int cnt = 0;
    for (int i = 0; i < color.size(); i++)
    {
        if (color[i] == true)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}