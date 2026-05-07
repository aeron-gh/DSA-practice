#include <bits/stdc++.h>
using namespace std;

int dp[20];
int f(string s, int idx = 0, bool tight = true, int lead = 1, int pre = 0)
{
    if (idx == s.size())
    {
        return 1;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int low = 0;
    int high = tight ? s[idx] - '0' : 9;

    int a = 0;
    for (int i = low; i < high; i++)
    {
        int newIdx = idx + 1;
        int newTight = tight and i == high;
        int newLead = lead and i == 0;
        if (lead == true or i != pre)
        {
            a += f(s, newIdx, newTight, newLead, i);
        }
    }

    return dp[idx] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> n;
    memset(dp, -1, sizeof dp);
    int a = f(to_string(n));
    memset(dp, -1, sizeof dp);

    int b = f(to_string(m - 1));

    cout << b - a;

    return 0;
}