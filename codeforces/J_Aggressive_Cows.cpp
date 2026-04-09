#include <bits/stdc++.h>
using namespace std;

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
  
int main()
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
    int l = 0;
    int r = 0;
    int a = INT_MIN;
    int b = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a < arr[i])
        {
            a = arr[i];
        }
        if (b > arr[i])
        {
            b = arr[i];
        }
    }

    r = abs(a - b);

    sort(arr.begin(), arr.end());
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