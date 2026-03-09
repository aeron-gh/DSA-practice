// Contest: https://codeforces.com/contests/677363  mid-term-exam
// Problem: I
// Link: https://codeforces.com/gym/677363/problem/I

#include <bits/stdc++.h>
using namespace std;

int red = 1;
int blue = -1;
int white = 0;

bool dfs()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    while (m--)
    {
        int a, b;
        cin >> a >> n;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> colors(n, white);
    for (int i = 0; i < n; i++)
    {
        if (colors[i] == white)
        {
            bool a = dfs();
            if (a == false)
            {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < colors.size(); i++)
    {
        
    }
    return 0;
}