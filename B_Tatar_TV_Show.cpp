#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        for (int i = 0; i <= n - k - 1; i++)
        {
            if (str[i] == '1')
            {
                str[i] = '0';
                if (str[i + k] == '0')
                {
                    str[i + k] = '1';
                }
                else
                {
                    str[i + k] = '0';
                }
            }
        }

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
            {

                cout << "NO" << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}