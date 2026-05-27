#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (q--)
    {
        int f;
        cin >> f;
        int l = 0;
        int r = n - 1;
        int idx = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] >= f)
            {
                idx = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (idx == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << arr[idx] - f << endl;
        }
    }

    return 0;
}