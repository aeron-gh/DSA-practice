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
        int n;
        cin >> n;
        int foo = 0, bar = 0, goo = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a == 0)
            {
                foo++;
            }
            else if (a == 1)
            {
                bar++;
            }
            else
            {
                goo++;
            }
        }
        int ans = 0;
        ans = ans + foo;
        foo = 0;
        int m = min(bar, goo);
        ans += m;
        bar -= m;
        goo -= m;

        while (true)
        {
            if (goo >= 3)
            {
                ans++;
                goo -= 3;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            if (bar >= 3)
            {
                ans++;
                bar -= 3;
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