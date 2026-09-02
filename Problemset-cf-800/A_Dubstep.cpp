#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> st;

    string str;
    cin >> str;
    string ans;
    for (int i = 0; i < str.size(); i++)
    {
        if (i+2 < str.size() && str[i] == 'W' and str[i + 1] == 'U' and str[i + 2] == 'B')
        {
            i += 2;
            ans += ' ';
        }
        else
        {
            // st.insert(i);
            ans += str[i];
        }
    }

    // if (str[str.size() - 2] != 'U' and str[str.size() - 1] != 'B')
    // {
    //     cout << str[str.size() - 2] << str[str.size() - 1];
    //     return 0;
    // }

    // if (ans[0] != ' ')
    // {
    //     cout << ans[0];
    // }
    bool foo = false;
        bool started = false;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == ' ')
        {
             if (started)
                foo = true;
        }
        else
        {
            if (foo == true)
            {
                cout << " ";
            }

            cout << ans[i];
            started = true;
            foo = false;
        }
    }

    // for (int i = 0; i < str.size(); i++)
    // {

    //     if (st.count(i))
    //     {
    //         // cout << str[i];
    //     }
    // }
    return 0;
}