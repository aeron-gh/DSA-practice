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

        string str;
        cin >> str;

        int foo = 0, bar = 0;
        bool possible = true;

        for (int i = 0; i < n; i++)
        {
            char ch = str[i];

            if (ch == 'R')
            {
                foo++;
            }
            else if (ch == 'B')
            {
                bar++;
            }
            // else
            // { 
            //     if ((foo > 0 && bar == 0) || (bar > 0 && foo == 0))
            //     {
            //         possible = false;
            //         break;
            //     }

            //     foo = 0;
            //     bar = 0;
            // }
        }

        if ((foo > 0 && bar == 0) || (bar > 0 && foo == 0))
        {
            possible = false;
        }

        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}