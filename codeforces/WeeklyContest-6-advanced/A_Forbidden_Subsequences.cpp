#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, int k, string &s, string &t, string &r)
{
    if (i == s.size())
    {
        return 1;
    }
    if (j == t.size())
    {
        return 0;
    }
    int ans = 0;
    if (s[i] == t[j] and s[i] != r[k])
    {
        ans = f(i + 1, j + 1, k + 1, s, t, r);
    }
    if (s[i] != t[j])
    {
        ans = f(i + 1, j, k, s, t, r);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t, r;
    cin >> s >> t >> r;
    cout << f(0, 0, 0, s, t, r);
    return 0;
}