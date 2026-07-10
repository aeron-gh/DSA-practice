#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    int foo = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        foo -= a;
        foo += b;
        ans = max(ans, foo);
    }
    cout << ans;

    return 0;
}