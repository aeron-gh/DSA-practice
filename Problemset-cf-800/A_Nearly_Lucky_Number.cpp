#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    while (n)
    {

        if (n % 10 == 4 or n % 10 == 7)
        {
            cnt++;
        }
        n /= 10;
    }
    
    if (cnt == 4 or cnt == 7)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}