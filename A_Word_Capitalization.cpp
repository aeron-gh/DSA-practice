#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    if (str[0] >= 'a' and str[0] <= 'z')
    {
        str[0] = str[0] - 32;
    }

    cout << str;
    return 0;
}