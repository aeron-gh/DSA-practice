#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    if (str[0] == 'c' or str[3] == 'f')
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}