#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> vec(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        if (vec[0] + vec[1] == vec[2])
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