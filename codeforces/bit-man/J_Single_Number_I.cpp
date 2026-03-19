#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        int no;
        cin >> no;
        ans = ans ^ no;
    }
    cout << ans;

    return 0;
}