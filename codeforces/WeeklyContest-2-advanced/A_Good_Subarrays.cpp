#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, t;
    cin >> n >> k >> t;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a = 0;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        a += arr[i];
    }
    if ((a / k) >= t)
    {
        cnt++;
    }
    for (int i = k; i < n; i++)
    {
        a += arr[i];
        a -= arr[i - k];
        if ((a / k) >= t)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}