#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        string str;
        cin >> str;
        if (str == "Icosahedron")
        {
            ans += 20;
        }
        else if (str == "Cube")
        {
            ans += 6;
        }
        else if (str == "Tetrahedron")
        {
            ans += 4;
        }
        else if (str == "Dodecahedron")
        {
            ans += 12;
        }
        else if (str == "Octahedron")
        {
            ans += 8;
        }
    }
    cout << ans;
    return 0;
}