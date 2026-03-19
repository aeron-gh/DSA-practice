#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    if (n == 0)
    {
        cout << "NO";
        return 0;
    }

    if (n & (n - 1))
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
