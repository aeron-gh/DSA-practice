#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(vector<int> arr, int mid, int k)
{
    int a = 0, p = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        a += (arr[i] + 1);
        if ((a - 1) > mid)
        {
            a = (arr[i] + 1);
            p++;
        }
    }

    return p <= k;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 1;
    int r = n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > l)
        {
            l = arr[i];
        }
        r += arr[i];
    }

    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (possible(arr, mid, k))
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