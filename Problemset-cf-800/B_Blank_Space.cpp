#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            cnt = 0;
        }
        else
        {
            cnt++;
            ans = max(cnt, ans);
        }
    }
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }
}
