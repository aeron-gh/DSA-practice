#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    string ptr;
    cin >> str >> ptr;
    reverse(str.begin(), str.end());
    if (str == ptr)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}