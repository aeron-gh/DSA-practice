#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int l = 1;
    int r = n;

    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        cout << "? "<< mid << endl;
        char ch;
        cin >> ch;
        if (ch == 'T')
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << "! " << ans << endl;
    return 0;
}