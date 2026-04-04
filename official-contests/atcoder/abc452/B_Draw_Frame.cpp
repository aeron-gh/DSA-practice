#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or i == n - 1)
            {
                arr[0][j] = '#';
                arr[n - 1][j] = '#';
            }
            else if (j == 0 or j == m - 1)
            {
                arr[i][0] = '#';
                arr[i][m - 1] = '#';
            }
            else
            {
                arr[i][j] = '.';
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
    return 0;
}