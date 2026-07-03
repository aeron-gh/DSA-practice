#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > k)
        {
            ans++;
            ans++;
        }
        else
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}