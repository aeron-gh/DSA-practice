#include <bits/stdc++.h>
using namespace std;
#define int long long

int factorCount(int no)
{
    int cnt = 0;
    for (int i = 1; i * i <= no; i++)
    {
        if (no % i == 0)
        {
            if (no == i)
            {
                cnt++;
            }
            else
            {
                cnt = cnt + 2;
            }
        }
    }
    return cnt;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (factorCount(a) > factorCount(b))
    {
        cout << 'A';
    }
    else if (factorCount(a) < factorCount(b))
    {
        cout << 'B';
    }
    else if (factorCount(a) == factorCount(b))
    {
        cout << "DRAW";
    }

    return 0;
}