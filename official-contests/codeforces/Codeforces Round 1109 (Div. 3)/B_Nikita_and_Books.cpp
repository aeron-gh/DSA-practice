#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int a[n + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int c = 0;

    for (int i = 1; i <= n; i++)
    {

        if (a[i] == i)
        {
            continue;
        }

        if (a[i] > i)
        {
            c += a[i] - i;
        }
        else
        {
            c = c - (i - a[i]);
        }

        if (c < 0)
        {
            cout << "NO" << endl;
            return;
        };
    }
    if (c < 0)
    {
        cout << "NO" << endl;
        return;
    };
    cout << "YES" << endl;
}

int32_t main()
{

    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
