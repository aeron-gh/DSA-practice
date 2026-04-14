#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(vector<int> arr, int mid, int k)
{
    int a = 0; 
    for (int i = 0; i < arr.size(); i++)
    {
         a += (arr[i] / mid);
    }

    return a >= k;
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
    int r = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > r)
        {
            r = arr[i];
        }
    }

    int ans = 0;
    while (l <= r)
    {
        int mid =  l + (r - l) / 2;
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