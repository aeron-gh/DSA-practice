#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        char arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int k = 0; k < n; k++) 
        {
            for (int i = 0; i < m; i++) 
            {
                for (int j = n - 2; j >= 0; j--) 
                {
                    if (arr[j][i] == '*' && arr[j + 1][i] == '.')
                    {
                        swap(arr[j][i], arr[j + 1][i]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}