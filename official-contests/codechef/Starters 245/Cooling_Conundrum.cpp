#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        double n, m;
        cin >> n >> m;
        int ans = 0;
        while (n != m)
        {
            ans += ceil(n / 10);
            n--;
        }
        cout << ans << endl;
    }
    return 0;
}