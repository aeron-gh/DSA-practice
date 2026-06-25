#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int a = 0;
    int b = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'A')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    
    if (a > b)
    {
        cout << "Anton";
    }
    else if (a < b)
    {
        cout << "Danik";
    }
    else
    {
        cout << "Friendship";
    }

    return 0;
}