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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        reverse(arr, arr + n);
        bool a = false;
        for (int i = 0; i < n - 2; i++)
        {
            if (arr[i] % arr[i + 1] != arr[i + 2])
            {
                cout << -1 << endl;
                a = true;
                break;
            }
        }

        if (a == false)
        {
            cout << arr[0] << " " << arr[1] << endl;
        }
    }
    return 0;
}