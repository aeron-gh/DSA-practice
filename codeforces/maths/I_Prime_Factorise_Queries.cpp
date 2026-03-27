#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const int n = 1e5;
    int spf[n + 1];
    for (int i = 1; i <= n; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] != i)
        {
            continue;
        }
        for (int j = i * i; j <= n; j += i)
        {
            spf[j] = min(spf[j], i);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {

        int no;
        cin >> no;
        map<int, int> mp;
        while (no != 1)
        {
            mp[spf[no]]++;
            no /= spf[no];
        }
        for (auto a : mp)
        {
            cout << a.first << '^' << a.second << " ";
        }cout << endl;
    }
    return 0;
}