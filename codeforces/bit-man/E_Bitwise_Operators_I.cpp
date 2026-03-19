#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << (a & b) << ' ' << (a | b) << ' ' << (a ^ b);

    return 0;
}