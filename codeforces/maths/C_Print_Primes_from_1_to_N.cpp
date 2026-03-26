#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<bool> vec(n + 1, true);
    vec[0] = false;
    vec[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (vec[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                vec[j] = false;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vec[i])
        {
            cout << i << " ";
            cnt++;
        }
    }

    cout << endl;
    cout << cnt;
    return 0;
}