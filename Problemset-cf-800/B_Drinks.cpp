#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long double n;
    cin >> n;
    long double a = 0;
    for (int i = 0; i < n; i++)
    {
        long double b;
        cin >> b;
        a += b / 100.0;
    }
    cout << (a / n) * 100;
    return 0;
}