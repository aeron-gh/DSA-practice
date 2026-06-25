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
        int n, l, r;
        cin >> n >> l >> r;
        l--;
        r--;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            if (i < l)
            {
                a += input;
            }
            if (i > r)
            {
                b += input;
            }
        }
        cout << max(a, b) << endl;
    }

    return 0;
}