#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double x;
    cin >> x;

    if (ceil(x / 5) == ceil((x + 1) / 5))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}