#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec(n + 1, 1);
    vec[0] = 0;
    vec[1] = 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (vec[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                vec[j] = 0;
            }
        }
    }

    vector<int> pre(n + 1);
    int foo = 0;
    for (int i = 0; i <= n; i++)
    {
        foo += vec[i];
        pre[i] = foo;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}