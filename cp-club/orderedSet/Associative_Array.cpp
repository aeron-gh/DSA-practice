#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> mpp;
    int q;
    cin >> q;
    while (q--)
    {
        int t, k;
        cin >> t >> k;
        if (t == 0)
        {
            int a;
            cin >> a;
            mpp[k] = a;
        }
        else
        {
            cout << mpp[k] << endl;
        }
    }

    return 0;
}