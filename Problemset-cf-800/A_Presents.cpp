#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ans[a - 1] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}