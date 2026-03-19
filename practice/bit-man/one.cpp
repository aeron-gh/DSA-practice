#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 13;
    string str;
    while (n >= 1)
    {
        char ch = (n % 2) + '0';
        str += ch;
        n = n / 2;
    }

    reverse(str.begin(), str.end());
    cout << str << endl;

    string no = str;
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
    // cout << stoi("10101") << endl;
    // cout << to_string(10);
    return 0;
}