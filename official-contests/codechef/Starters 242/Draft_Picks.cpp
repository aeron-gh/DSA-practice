#include <bits/stdc++.h>
using namespace std;
#define int double

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> mpp;
        int a = k;

        for (int i = 0; i < ceil(a / n) and k; i++)
        {
            for (int i = 1; i <= n and k != 0; i++, k--)
            {
                mpp[i] += k;
            }

            for (int i = n; i >= 1 and k != 0; i--, k--)
            {
                mpp[i] += k;
            }
        }
        
        int ans = -1;
        for (auto a : mpp)
        {
            ans = max((int)a.second, ans);
        }

        cout << ans << endl;
    }

    return 0;
}