#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int a = n * 3;
        int b = (n * 3) - 1;

        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
            cout << a << " ";
            cout << b << " ";
            a = a - 2;
            b = b - 2;
        }
        cout << endl;
    }

    return 0;
}