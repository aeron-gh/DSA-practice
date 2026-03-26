#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;

    int n = 1000000;
    vector<int> vec(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            vec[j]++;
        }
    }

    while (q--)
    {
        int no;
        cin >> no;
        cout << vec[no] << endl;
    }

    return 0;
}