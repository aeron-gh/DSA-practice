#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (mx < arr[i])
        {
            mx = arr[i];
        }
    }

    int ans[n];
    int hcf = 0;
    for (int i = 0; i < n; i++)
    {
        ans[i] = mx - arr[i];
        hcf = __gcd(ans[i], hcf);
    }
    if (hcf == 0)
    {
        cout << 0 << " " << 0;
        return 0;
    }
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        y += ans[i] / hcf;
    }
    cout << y << " " << hcf;
    return 0;
}