#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(vector<int> arr, int mid, int x)
{
    int sz = arr.size();
    int a = 0;

    for (int i = 0; i < sz; i++)
    {
        if (mid >= arr[i])
        {
            a += (mid - arr[i]);
        }
    }

    return a <= x;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0;
    int r = 1e10;

    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (possible(arr, mid, x))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--)
    {
        solve();
    }

    return 0;
}