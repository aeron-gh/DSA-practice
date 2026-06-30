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
        int arr[n / 2];
        int a = 4;
        for (int i = 0; i < n; i++)
        {
            arr[i] = a - 1;
            a = a * 2;
        }

        if (k > n)
        {
            cout << n << endl;
            continue;
        }
        int count = __builtin_popcount(n / k);
        cout << count * k << endl;
    }

    return 0;
}