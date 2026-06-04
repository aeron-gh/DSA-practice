#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int j = n - 1;
    for (int i = 1; i <= n / 2; i++)
    {   
        if (i % 2 == 0 and j % 2 == 0)
        {
            cout << "YES";
            return 0;
        }
        j--;
    }
    cout << "NO";

    return 0;
}