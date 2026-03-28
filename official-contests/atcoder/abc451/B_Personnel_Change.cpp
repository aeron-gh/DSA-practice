#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> vec(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int no1, no2;
        cin >> no1 >> no2;
        vec[no1]--;
        vec[no2]++;
    }

    for (int i = 1; i <= m; i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}