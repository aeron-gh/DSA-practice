#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans & arr[i];
    }
    cout << ans << " ";
    ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans | arr[i];
    }

    cout << ans << " ";

    ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans;

    return 0;
}