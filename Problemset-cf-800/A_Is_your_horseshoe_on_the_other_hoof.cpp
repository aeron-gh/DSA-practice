#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> mp;
    for (int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    int b = 0;
    for (auto a : mp)
    {
       b += a.second - 1;
    }
    cout << b ;

    return 0;
}