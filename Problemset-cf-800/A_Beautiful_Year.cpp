#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin >> a;
    while (true)
    {
        a++;
        string str = to_string(a);

        int b = 0;
        int i;
        for (i = 0; i < str.size(); i++)
        {
            int a = 0;
            for (int j = 0; j < str.size(); j++)
            {
                if (i != j)
                {
                    if (str[i] == str[j])
                    {   b = 1;
                        a = 1;
                        break;
                    }
                }
            }
            if (a == 1)
            {
                break;
            }
        }
     
        if (b == 0)
        {
            cout << str;
            break;
        }
    }

    return 0;
}