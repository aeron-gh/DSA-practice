#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch >= 'A' and ch <= 'Z')
        {
            ch += 32;
            str[i] = ch;
        }
    }
    pair<int, int> pre[n];
    int foo = 0, bar = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
        {
            foo++;
        }
        else
        {
            bar++;
        }
        pre[i].first = foo;
        pre[i].second = bar;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l > 0)
        {
            if (pre[r].first - pre[l - 1].first == pre[r].second - pre[l - 1].second)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if (pre[r].first - 0 == pre[r].second - 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}