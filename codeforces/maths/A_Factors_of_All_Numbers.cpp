#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec[n + 1];
    // tc n * log (n)
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            vec[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}