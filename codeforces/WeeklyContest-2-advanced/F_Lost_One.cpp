#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r;
    cin >> r;
    r--;
    int l = 0;
    int ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int a;
        cout << "? " << l + 1 << " " << mid + 1 << endl;
        cin >> a;
        if (a == 0)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }

    cout << "! " << ans + 1 << endl;
    return 0;
}