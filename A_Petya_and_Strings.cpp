#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' and s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
        if (t[i] >= 'A' and t[i] <= 'Z')
        {
            t[i] = t[i] + 32;
        }
    }

    if (s == t)
    {
        cout << 0;
    }
    else if (s > t)
    {
        cout << 1;
    }
    else
    {
        cout << -1;
    }

    return 0;
}