#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string no = "1101";
    int ans = 0;
    int pw = 1;
    for (int i = no.size() - 1; i >= 0; i--)
    {
        if (no[i] == '1')
        {
            ans += pw;
        }
        pw *= 2;
    }

    cout << ans;
    return 0;
}