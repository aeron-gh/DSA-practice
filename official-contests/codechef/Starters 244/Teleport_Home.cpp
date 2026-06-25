#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int d, t;
    cin >> d >> t;
    if (t - d > 0)
    {
        cout << 0;
    }
    else
    {
        cout << d - t;
    }

    return 0;
}