#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int spf[n + 1], cnt[n + 1];
    for (int i = 1; i <= n; i++)
    {
        spf[i] = i;
        cnt[i] = 0;
    }  
    
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] != i)
        {
            continue;
        }
        for (int j = i; j <= n; j += i)
        {
            spf[j] = min(spf[j], i);
            cnt[j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 2)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}