#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(vector<int> arr, int mid, int h)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int a = arr[i] / mid;
        if (arr[i] % mid == 0)
        {
            h = h - a;
        }
        else
        {
            h = h - (a + 1);
        }
    }

    return h >= 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 1;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (r < arr[i])
        {
            r = arr[i];
        }
    }

    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (possible(arr, mid, h))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans;

    return 0;
}