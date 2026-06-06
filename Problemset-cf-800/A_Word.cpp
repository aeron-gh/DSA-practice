#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int lc = 0, up = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' and str[i] <= 'z')
        {
            lc++;
        }
        else
        {
            up++;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (lc >= up)
        {
            if (str[i] >= 'a' and str[i] <= 'z')
            {
            }
            else
            {
                str[i] = str[i] + 32;
            }
        }
        else
        {
            if (str[i] >= 'a' and str[i] <= 'z')
            {
                str[i] = str[i] - 32;
            }
            else
            {
            }
        }
    }

    cout << str;

    return 0;
}