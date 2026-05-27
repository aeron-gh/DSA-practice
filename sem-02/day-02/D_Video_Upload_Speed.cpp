#include <bits/stdc++.h>
using namespace std;

#define int long long

bool pos(vector<int> &arr, int n, int h, int speed)
{
    int hr = 0;
    for (int i = 0; i < n; i++)
    {
        hr = hr + ((arr[i] + speed - 1) / speed);
        if (hr > h)
        {
            return false;
        }
    }

    return hr <= h;
}

signed main()
{
    int n, h;
    cin >> n >> h;

    vector<int> arr(n);

    int m = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m = max(m, arr[i]);
    }

    int low = 1, high = m;
    int ans = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (pos(arr, n, h, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}