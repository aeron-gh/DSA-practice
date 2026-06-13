#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    string ans;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' and str[i] <= 'z')
        {
        }
        else
        {
            ans += str[i];
        }
    }
    cout << ans;
    return 0;
}