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
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        vector<int> f(n);
        vector<int> cv(n);

        for (auto &a : v)cin >> a;
        for (auto &a : f)cin >> a;
        cv = v;

        int b = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] < f[i])
            {
                b = INT_MAX;
                break;
            }
            while (v[i] != f[i] and v[i] > f[i])
            {
                v[i]--;
                b++;
            }
        }

        sort(cv.begin(), cv.end());
        sort(f.begin(), f.end());
        int a = k;

        for (int i = 0; i < n; i++)
        {
            if (cv[i] < f[i])
            {
                a = INT_MAX;
                break;
            }
            while (cv[i] != f[i] and cv[i] > f[i])
            {
                cv[i]--;
                a++;
            }
        }

        if (a == INT_MAX and b == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << min(a, b) << endl;
        }
    }

    return 0;
}