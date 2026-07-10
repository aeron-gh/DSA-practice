#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    while (k--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == 'B' and str[i + 1] == 'G')
            {
                swap(str[i], str[i + 1]);
                i++;
            }
        }
    }
    cout << str;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}
