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
    vector<int> pre(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
        pre[i] += ans;
    }

    while (k--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(l == 0){
            cout << pre[r] << endl;
            continue;
        }
        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}