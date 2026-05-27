#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[600][5001];

int f(int pos, int cw, vector<int> &wei, vector<int> &vec, int n, int w)
{
    if (pos >= n)
    {
        return 0;
    }

    if (dp[pos][cw] != -1)
    {
        return dp[pos][cw];
    }
   
    int a = 0;
    if (cw + wei[pos] <= w)
    {
        a = vec[pos] + f(pos + 3, cw + wei[pos], wei, vec, n, w);
    }

    int b = f(pos + 1, cw, wei, vec, n, w);

    return dp[pos][cw] = max(a, b);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin >> n >> w;
    vector<int> vec(n);
    vector<int> wei(n);
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec[i] = a;
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        wei[i] = a;
    }
    
    memset(dp, -1, sizeof dp);
    cout << f(0, 0, wei, vec, n, w);
    return 0;
}