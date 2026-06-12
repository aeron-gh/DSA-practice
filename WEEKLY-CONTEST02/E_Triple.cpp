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
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            mpp[a]++;
        }

        int found = false;
        for (auto a : mpp)
        {
            if (a.second >= 3)
            {
                cout << a.first << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}