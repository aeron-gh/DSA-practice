#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int ans = 0;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        int c = 0;
        int a = arr[i];
        while (a)
        {
            c += a & 1;
            a >>= 1;
        }
        ans += c;
    }

    int idx = 0;
    int foo = ans;

    for (int i = k; i < n; i++)
    {

        int c = 0;
        int a = arr[i];
        while (a)
        {
            c += a & 1;
            a >>= 1;
        }

        int g = 0;
        a = arr[i - k];
        while (a)
        {
            g += a & 1;
            a >>= 1;
        }
        ans += c;
        ans -= g;

        if (ans > foo)
        {
            foo = ans;
            idx = i - k + 1;
        }
    }

    cout << foo << endl;
    for (int i = idx; i < idx + k; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}