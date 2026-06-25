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
        int n, k;
        cin >> n >> k;
        int a = 1;
        while (a <= n)
        {
            a += k;
        }
        cout << a - k << endl;
    }

    return 0;
}