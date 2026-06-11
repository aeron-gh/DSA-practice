#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = 0;

        for (int j = 30; j >= 0; j--)
        {
            int f = 0;

            for (int x : a)
            {
                if (((x >> j) & 1) == 0)
                {
                    f++;
                }
            }

            if (f <= k)
            {
                k -= f;
                ans |= (1LL << j);
            }
        }

        cout << ans << endl;
    }
}