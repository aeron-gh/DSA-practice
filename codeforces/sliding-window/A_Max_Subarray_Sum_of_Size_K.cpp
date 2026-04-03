#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a = 0;
    for (int i = 0; i < k; i++)
    {
        a += arr[i];
    }
    int ans = a;
    for (int i = k; i < n; i++)
    {
        a = a + arr[i];
        a = a - arr[i - k];
        ans = max(a, ans);
    }

    cout << ans;
    return 0;
}