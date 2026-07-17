#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    string ans;

  
    for (int i = 0; i < a.size(); i++)
    {
        if ((a[i] == '1' and b[i] == '0') or (a[i] == '0' and b[i] == '1'))
        {
            ans += '1';
        }
        else
        {
            ans += '0';
        }
    }
    cout << ans;
    return 0;
}