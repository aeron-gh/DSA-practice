#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int &v : a)
        {
            cin >> v;
        }

        vector<int> divs;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                divs.push_back(i);
                if (i * i != x)
                {
                    divs.push_back(x / i);
                }
            }
        }

        // dp[p] = can we make product p?
        unordered_map<int, bool> dp;

        int ans = 1;
        dp[1] = true;

        for (int v : a)
        {
            // v cannot be part of a product equal to x
            if (x % v != 0)
            {
                continue;
            }

            vector<int> cur;

            for (auto [p, ok] : dp)
            {
                if (!ok)
                {
                    continue;
                }

                long long np = 1LL * p * v;

                if (np <= x && x % np == 0)
                {
                    cur.push_back(np);
                }
            }

            for (int p : cur)
            {
                dp[p] = true;
            }

            if (dp[x])
            {
                ans++;
                dp.clear();
                dp[1] = true;
                dp[v] = true;
            }
        }

        cout << ans << '\n';
    }
}