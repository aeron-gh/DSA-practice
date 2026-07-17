#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int ans = 1;
    string st;
    cin >> st;
    while (n != 1)
    {
        string str;
        cin >> str;
        if (str != st)
        {
            st = str;
            ans++;
        }
        st = str;
        n--;
    }
    cout << ans;
    return 0;
}