#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1)
    {
        mp[n]++;
    }

    for (auto a : mp)
    {
        cout << a.first << '^' << a.second << " ";
    }
 
    return 0;
}