#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    cin >> str;

    int a = 0;
    int b = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'a')
        {
            a++;
        }
        else
        {
            b++;
        }

        if (i % 2 != 0)
        {
            if (a != b)
            {
                if (str[i] == 'a')
                {
                    ans++;
                    str[i] = 'b';
                    a--;
                    b++;
                }
                else
                {
                    ans++;
                    str[i] = 'a';
                    b--;
                    a++;
                }
            }
        }
    }
    cout << ans << endl;
    cout << str;
    return 0;
}