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
        int x, y;
        cin >> x >> y;
        vector<int> v;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (x / i == i)
                {
                    v.push_back(x / i);
                }
                else
                {
                    v.push_back(x / i);
                    v.push_back(i);
                }
            }
        }
        
        bool a = true;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == y)
            {
                cout << "YES" << endl;
                a = false;
                break;
            }
        }

        if (a == true)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}