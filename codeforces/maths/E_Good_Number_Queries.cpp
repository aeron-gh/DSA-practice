#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 1000000;
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
    
    vector<int> pCounts(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            pCounts[j]++;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int no;
        cin >> no;
        if (vec[pCounts[no]])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}