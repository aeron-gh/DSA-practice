#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr1[n];
        int arr2[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        int ans = 0;
        int mx = -1;
        int ind = -1;

        for (int i = 0; i < n; i++)
        {
            int a = min(arr1[i], arr2[i]);
            if (a > mx)
            {
                ind = i;
                mx = a;
            }
        }

        // cout << ind << " ";
        for (int i = 0; i < n; i++)
        {
            if (i != ind)
            {
                ans += max(arr1[i], arr2[i]);
            }
            else
            {
                ans += arr1[i];
            }
            // cout << ans << " ";
        }
        ans += arr2[ind];
        cout << ans << endl;
    }

    return 0;
}