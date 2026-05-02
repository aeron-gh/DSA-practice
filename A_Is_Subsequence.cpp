#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string t;
    cin >> s >> t;

    int j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == s[j])
        {
            j++;
        }
    }

    if (j == s.size())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}