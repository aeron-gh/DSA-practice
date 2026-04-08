#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int l = 0;
    int r = 1e9;
    
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (mid*mid <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans;

    return 0;
}