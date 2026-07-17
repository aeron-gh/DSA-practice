#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '*')
        {
            ans = max(ans, c);
            c = 0;
        }
        else
        {
            c++;
        }
    }
    ans = max(ans, c);
    if (ans % 2 == 0)
    {
        cout << ans / 2 << endl;
    }
    else
    {
        cout << ans / 2 + 1 << endl;
    }
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
