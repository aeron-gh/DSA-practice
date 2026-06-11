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
        vector<string> vec(n);
        // map<string, int> mpp;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            // sort(str.begin(), str.end());
            vec[i] = str;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (vec[i][0] == vec[j][0] and vec[i][1] != vec[j][1])
                {
                    ans++;
                }
                if (vec[i][1] == vec[j][1] and vec[i][0] != vec[j][0])
                {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}