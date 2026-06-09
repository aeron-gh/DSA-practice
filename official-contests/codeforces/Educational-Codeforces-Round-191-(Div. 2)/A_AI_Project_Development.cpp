#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        double n, x, y, z;
        cin >> n >> x >> y >> z;
        double a = (n / (x + y)); // time
        double b = z;
        n -= z * x;
        b += (n / (x + (y * 10))); // time with ai
        double ans = min(a, b);

        cout << ceil(ans) << endl;
    }

    return 0;
}