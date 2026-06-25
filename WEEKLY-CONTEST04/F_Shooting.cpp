
#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        arr.push_back({a, i});
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += 1LL * arr[i].first * i;
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].second << " ";
    }

    return 0;
}