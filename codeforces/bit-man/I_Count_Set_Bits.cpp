#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;;
    int pw = 1;
    while (pw <= n)
    {
        pw = pw * 2;
    }
    pw = pw / 2;
    while (pw > 0)
    {
        if (n >= pw)
        {
            n = n - pw;
            ans++;
        }
        pw = pw / 2;
    }

    cout << ans;
    return 0;
}