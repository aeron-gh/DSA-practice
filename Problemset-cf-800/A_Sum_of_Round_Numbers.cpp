#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> vec;
    int a = 0;
    while (n)
    {
        if (n % 10 != 0)
        {
            vec.push_back((n % 10) * (int)(pow(10, a)));
            // cout << (n % 10) * pow(10, a);
        }
        a++;
        n = n / 10;
    }
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
