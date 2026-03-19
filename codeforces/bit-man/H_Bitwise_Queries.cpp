#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int no;
    cin >> no;
    int q;
    cin >> q;

    while (q--)
    {
        int t;
        cin >> t;
        int i;
        cin >> i;

        if (t == 1)
        {
            if ((no & (1LL << i)) == 0) // wrong (no & (1LL << i) == 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else if (t == 2)
        {
            no = (1LL << i) | no;
            cout << no << endl;
        }
        else if (t == 3)
        {
            no = ~(1LL << i) & no;
            cout << no << endl;
        }
        else if (t == 4)
        {
            no = (1LL << i) ^ no;
            cout << no << endl;
        }
    }

    return 0;
}