#include <bits/stdc++.h>
using namespace std;

#define int long long

bool possible(vector<int> arr, int mid, int k)
{
    int a = arr[0];
    // int cnt = 1;
    k--;
    for (int i = 1; i < arr.size(); i++)
    {
        if (abs(a - arr[i]) >= mid)
        {
            a = arr[i];
            // cnt++;
            k--;
        }
    }
    return k <= 0;
    // return cnt >= k;
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
    sort(arr.begin(), arr.end());
    int l = 0;
    int r = arr[n - 1] - arr[0];

    int ans = 0;
    // mid => min dis bw two
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (possible(arr, mid, k))
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