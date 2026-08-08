#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << (n / 2) - 1 << endl;
    }
    else
    {
        cout << (n / 2) << endl;
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
