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
        int a, b;
        cin >> a >> b;
        string str, st;
        cin >> str >> st;

        string ans;
        int n = min(a, b);

        for (int i = 0; i < n; i++)
        {
            if (str[i] == st[i])
            {
                ans += str[i];
            }
            else
            {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}