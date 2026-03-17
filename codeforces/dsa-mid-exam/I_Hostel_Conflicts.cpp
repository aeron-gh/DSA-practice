// Contest: https://codeforces.com/contests/677363  mid-term-exam
// Problem: I
// Link: https://codeforces.com/gym/677363/problem/I

#include <bits/stdc++.h>
using namespace std;

int red = 1;
int blue = -1;
int white = 0;

bool dfs(int node, vector<int> &colors, vector<int> adj[], int color)
{
    colors[node] = color;
    for (auto x : adj[node])
    {
        if (colors[x] == white)
        {
            bool a = dfs(x, colors, adj, color == red ? blue : red);
            if (a == false)
            {
                return false;
            }
        }
        else if (colors[x] == color)
        {
            return false;
        }
    }
    return true;
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

    vector<int> colors(n + 1, white);
    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == white)
        {
            bool a = dfs(i, colors, adj, red);
            if (a == false)
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= colors.size(); i++)
    {
        if (colors[i] == red)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    for (int i = 1; i <= colors.size(); i++)
    {
        if (colors[i] == blue)
        {
            cout << i << " ";
        }
    }
    return 0;
}