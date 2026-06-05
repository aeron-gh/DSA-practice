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
        string str;
        cin >> str;
        if (str == "++X" or str == "X++")
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    cout << ans;

    return 0;
}