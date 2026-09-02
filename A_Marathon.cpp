#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int a;
    cin >> a;
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        int foo;
        cin >> foo;
        if (foo > a)
        {
            ans++;
        }
    }
    cout << ans << endl;
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
    }
}
