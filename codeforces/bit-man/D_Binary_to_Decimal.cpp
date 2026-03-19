#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int sz = str.size() - 1;
    int ans = 0;
    // while (sz != -1)
    // {
    //     if (str[sz] == '1')
    //     {
    //         ans += pow(2, sz - 0);
    //     }
    //     sz--;
    // }
    int pw = 1;
    for (int i = sz; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            ans += pw;
        }
        pw *= 2;
    }

    cout << ans;
    return 0;
}